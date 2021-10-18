/**
 * @author: 武连增
 */

#include "../../../include/controller/command/AbstractChessCommand.h"

AbstractChessCommand::AbstractChessCommand() :
        lastPosX(0),
        lastPosY(0),
        curPosX(0),
        curPosY(0) {}

void AbstractChessCommand::move() {
    if (!isAbleMoved()) {
        return;
    }
}

void AbstractChessCommand::undo() {

}

bool AbstractChessCommand::isAbleMoved() const noexcept {
    return !isOutOfRanged() && isValid();
}

bool AbstractChessCommand::isOutOfRanged() const noexcept {
    int nextPosX = 0, nextPosY = 0;
    return nextPosX >= 0 && nextPosX <= 8 && nextPosY >= 0 && nextPosY <= 9;
}

AbstractChessCommand::~AbstractChessCommand() noexcept = default;


