/**
 * @author: 武连增
 */


#include "RookChessCommand.h"

RookChessCommand::RookChessCommand(Chess chess) :
        AbstractChessCommand(chess) {}

bool RookChessCommand::isValid() const noexcept {
    bool isXNotChanged = nextPosX - curPosX != 0;

    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    if (this->chess->team == PositionMessage::position[nextPosX][nextPosY].character) {
        return false;
    }

    // 检查移动是否为直线
    if (nextPosY - curPosY != 0 && isXNotChanged) {
        return false;
    }

    // 检查移动路径上是否有其他棋子
    // 通过x坐标是否改变来判断车棋子移动方式
    int start = isXNotChanged ? curPosY : curPosX;
    int end = isXNotChanged ? nextPosY : nextPosX;
    // 确定坐标是递增还是递减
    int change = end - start >= 0 ? 1 : -1;
    int x = 0;
    int y = 0;
    for (int i = start; i < end; i += change) {
        x = isXNotChanged ? curPosX : i;
        y = isXNotChanged ? i : curPosY;
        if (PositionMessage::position[x][y].isFilled) {
            return false;
        }
    }
    return true;
}
