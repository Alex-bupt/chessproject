/**
 * @author: 武连增
 */


#include <cmath>
#include "../../../include/controller/command/SoldierChessCommand.h"

SoldierChessCommand::SoldierChessCommand(Chess chess, ChessView chessView) :
        soldierChess(chess),
        soldierChessView(chessView) {}

bool SoldierChessCommand::isValid() const noexcept{
    int nextPosX = 0, nextPosY = 0;

    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    int xOffset = nextPosX - curPosX;
    int yOffset = nextPosY - curPosY;

    // 检查是否只移动了一格
    if (abs(xOffset) + abs(yOffset) > 1) {
        return false;
    }

    // 检查是否能够横移
    // TODO: 从SoldierChessModel获取是否在本方界内
    bool isDefense = this->soldierChess;
    if (isDefense && xOffset) {
        return false;
    }

    // 检查是否后移
    // 若后移，team + yOffset为0或1
    // 0或1右移1位为0
    int team = 0;
    if (yOffset) {
        int judge = (team + yOffset) >> 1;
        if (!judge) {
            return false;
        }
    }
    return true;
}
