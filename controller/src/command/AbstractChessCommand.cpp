/**
 * @author: 武连增
 */

#include <AbstractChessCommand.h>

AbstractChessCommand::AbstractChessCommand(Chess chess) :
        lastPosX(0),
        lastPosY(0),
        curPosX(0),
        curPosY(0),
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
    if (ChessBoard::position[nextPosX][nextPosY].isFilled) {
        // TODO 吃子
    }
    this->chess->setCoordinate(curPosX, curPosY);
    if (isVictory()) {
        ChessBoard::victory = true;
    }
    int type = ChessBoard::position[lastPosX][lastPosY];
    ChessBoard::position[lastPosX][lastPosY] = 0;
    ChessBoard::position[curPosX][curPosY] = type;
    return true;
}

void AbstractChessCommand::undo() {
    this->chess->setCoordinate(lastPosX, lastPosY);
}

bool AbstractChessCommand::isAbleMoved() const noexcept {
    return !isOutOfRanged() && isValid();
}

bool AbstractChessCommand::isOutOfRanged() const noexcept {
    return nextPosX >= 0 && nextPosX <= 8 && nextPosY >= 0 && nextPosY <= 9;
}

void AbstractChessCommand::setNextPos(int x, int y) {
    this->nextPosY = y;
    this->nextPosX = x;
}

bool AbstractChessCommand::isVictory() {
    auto redMarshal = ChessesManager::RedMarshal[0];
    auto blackMarshal = ChessesManager::BlackMarshal[0];
    if (redMarshal.isAlive && blackMarshal.isAlive) {
        return false;
    }
    if (redMarshal.x != blackMarshal.x) {
        return false;
    }
    for (int y = redMarshal.y, x = redMarshal.x; y <= 9; ++y) {
        if (ChessBoard::position[x][y] >= 2) {
            return false;
        }
        if (ChessBoard::position[x][y] == 1) {
            break;
        }
    }
    return true;
}

AbstractChessCommand::~AbstractChessCommand() noexcept = default;


