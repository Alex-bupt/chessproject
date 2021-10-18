/**
 * @author: 武连增
 */

#include <AbstractChessCommand.h>

AbstractChessCommand::AbstractChessCommand(Chess chess, ChessView chessView) :
        lastPosX(0),
        lastPosY(0),
        curPosX(0),
        curPosY(0),
        chess(chess),
        chessView(chessView) {}

void AbstractChessCommand::move() {
    if (!isAbleMoved()) {
        return;
    }
    lastPosX = curPosX;
    lastPosY = curPosY;
    // curPosX = nextPosX;
    // curPosY = nextPosY;
    this->chess->setCoordinate(curPosX, curPosY);
}

void AbstractChessCommand::undo() {
    this->chess->setCoordinate(lastPosX, lastPosY);
}

bool AbstractChessCommand::isAbleMoved() const noexcept {
    return !isOutOfRanged() && isValid();
}

bool AbstractChessCommand::isOutOfRanged() const noexcept {
    int nextPosX = 0, nextPosY = 0;
    return nextPosX >= 0 && nextPosX <= 8 && nextPosY >= 0 && nextPosY <= 9;
}

AbstractChessCommand::~AbstractChessCommand() noexcept = default;


