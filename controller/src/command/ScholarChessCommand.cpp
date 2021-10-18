/**
 * @author: 武连增
 */


#include "../../../include/controller/command/ScholarChessCommand.h"
#include <cmath>
ScholarChessCommand::ScholarChessCommand(Chess chess, ChessView chessView) :
        scholarChess(chess),
        scholarChessView(chessView) {}

bool ScholarChessCommand::isValid() const noexcept {
    int nextPosX = 0, nextPosY = 0;

    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
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
    int team = scholarChess;
    nextPosY -= (!team) * 7;
    return nextPosX >= 3 && nextPosX <= 5 && nextPosY >= 0 && nextPosY <= 2;
}
