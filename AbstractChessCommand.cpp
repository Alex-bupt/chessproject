/**
 * @author: 武连增
 */

#include "AbstractChessCommand.h"
#include "chessboard.h"

AbstractChessCommand::AbstractChessCommand(Chess chess) :
        lastPosX(0),
        lastPosY(0),
        curPosX(chess->x),
        curPosY(chess->y),
        nextPosX(0),
        nextPosY(0),
        chess(chess) {}

bool AbstractChessCommand::move() {
    if (!isAbleMoved()) {
        return false;
    }
    lastPosX = curPosX;
    lastPosY = curPosY;
    curPosX = nextPosX;
    curPosY = nextPosY;
    if (PositionMessage::position[nextPosX][nextPosY].isFilled) {
        for (auto& oneChess : ChessesManager::getInstance().chesses) {
            if (nextPosX == oneChess->x && nextPosY == oneChess->y) {
                oneChess->isAlive = false;
                oneChess->setCoordinate(-1,-1);
                break;
            }
        }
    }
    this->chess->setCoordinate(curPosX, curPosY);
    if (isVictory()) {
//        PositionMessage::victory = true;
    }
    int type = PositionMessage::position[lastPosX][lastPosY].piece;
    PositionMessage::position[lastPosX][lastPosY].piece = 0;
    PositionMessage::position[lastPosX][lastPosY].character = -1;
    PositionMessage::position[lastPosX][lastPosY].isFilled = false;
    PositionMessage::position[curPosX][curPosY].piece = type;
    PositionMessage::position[curPosX][curPosY].character = chess->team;
    PositionMessage::position[curPosX][curPosY].isFilled = true;
    ChessBoard::conversion();
    return true;
}

void AbstractChessCommand::undo() {
    this->chess->setCoordinate(lastPosX, lastPosY);
    int type = PositionMessage::position[curPosX][curPosY].piece;
    PositionMessage::position[lastPosX][lastPosY].piece = type;
    PositionMessage::position[curPosX][curPosY].piece = 0;
    //TODO 把吃掉的棋子显示回来
}

bool AbstractChessCommand::isAbleMoved() const noexcept {
    return isOutOfRanged() && isValid();
}

bool AbstractChessCommand::isOutOfRanged() const noexcept {
    return nextPosX >= 0 && nextPosX <= 8 && nextPosY >= 0 && nextPosY <= 9;
}

void AbstractChessCommand::setNextPos(int x, int y) {
    this->nextPosY = y;
    this->nextPosX = x;
}

bool AbstractChessCommand::isVictory() {
    auto redMarshal = ChessesManager::getInstance().RedMarshal[0];
    auto blackMarshal = ChessesManager::getInstance().BlackMarshal[0];
    if (redMarshal.isAlive && blackMarshal.isAlive) {
        return false;
    }
    if (redMarshal.x != blackMarshal.x) {
        return false;
    }
    for (int y = redMarshal.y, x = redMarshal.x; y <= 9; ++y) {
        if (PositionMessage::position[x][y].piece >= 2) {
            return false;
        }
        if (PositionMessage::position[x][y].piece == 1) {
            break;
        }
    }
    return true;
}

AbstractChessCommand::~AbstractChessCommand() noexcept = default;


