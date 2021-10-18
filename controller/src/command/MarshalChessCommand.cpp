/**
 * @author: 武连增
 */


#include "../../../include/controller/command/MarshalChessCommand.h"
#include <cmath>
MarshalChessCommand::MarshalChessCommand(Chess chess, ChessView chessView) :
        marshalChess(chess),
        marshalChessView(chessView) {}

bool MarshalChessCommand::isValid() const noexcept {
    int nextPosX = 0, nextPosY = 0;
    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    unsigned uXOffset = abs(nextPosX - curPosX);
    unsigned uYOffset = abs(nextPosY - curPosY);
    // 检查是否走一格
    if (uXOffset + uYOffset > 1) {
        return false;
    }
    return true;
}

bool MarshalChessCommand::isOutOfRanged() const noexcept {
    int nextPosX = 0, nextPosY = 0;
    int team = marshalChess;
    nextPosY -= (!team) * 7;
    return nextPosX >= 3 && nextPosX <= 5 && nextPosY >= 0 && nextPosY <= 2;
}
