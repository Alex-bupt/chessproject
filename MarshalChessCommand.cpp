/**
 * @author: 武连增
 */


#include "MarshalChessCommand.h"
#include <cmath>
#include <iostream>

MarshalChessCommand::MarshalChessCommand(Chess chess) :
        AbstractChessCommand(chess) {}

bool MarshalChessCommand::isValid() const noexcept {
    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        std::cout << "---False1\n";
        return false;
    }

    if (this->chess->team == PositionMessage::position[nextPosX][nextPosY].character) {
        std::cout << "---False2\n";
        return false;
    }

    unsigned uXOffset = abs(nextPosX - curPosX);
    unsigned uYOffset = abs(nextPosY - curPosY);
    // 检查是否走一格
    if (uXOffset + uYOffset > 1) {
        std::cout << "---False3\n";
        return false;
    }
    return true;
}

bool MarshalChessCommand::isOutOfRanged() const noexcept {
    int nextPosX = this->nextPosX, nextPosY = this->nextPosY;
    int team = chess->team;
    nextPosY -= (!team) * 7;
    return nextPosX >= 3 && nextPosX <= 5 && nextPosY >= 0 && nextPosY <= 2;
}
