/**
 * @author: 武连增
 */


#include <cmath>
#include "ScholarChessCommand.h"

ScholarChessCommand::ScholarChessCommand(Chess chess) :
        AbstractChessCommand(chess) {}

bool ScholarChessCommand::isValid() const noexcept {
    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    if (this->chess->team == PositionMessage::position[nextPosX][nextPosY].character) {
        return false;
    }

    unsigned uXOffset = abs(nextPosX - curPosX);
    unsigned uYOffset = abs(nextPosY - curPosY);
    // 检查是否走斜线
    if (uXOffset != 1 || uYOffset != 1) {
        return false;
    }
    return true;
}

bool ScholarChessCommand::isOutOfRanged() const noexcept {
    int nextPosX = 0, nextPosY = 0;
    int team = chess->team;
    nextPosY -= (!team) * 7;
    return nextPosX >= 3 && nextPosX <= 5 && nextPosY >= 0 && nextPosY <= 2;
}
