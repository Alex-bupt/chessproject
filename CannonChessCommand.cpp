/**
 * @author: 武连增
 */

#include "CannonChessCommand.h"
#include <cstdlib>
#include <iostream>

CannonChessCommand::CannonChessCommand(Chess chess) :
        AbstractChessCommand(chess) {}

bool CannonChessCommand::isValid() const noexcept {
    bool isXChanged = nextPosX != curPosX;

    if (this->chess->team == PositionMessage::position[nextPosX][nextPosY].character) {
        return false;
    }

    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    // 检查移动是否为直线
    if (nextPosY != curPosY && isXChanged) {
        return false;
    }

    // 通过x坐标是否改变来判断炮棋子移动方式
    int start = isXChanged ? curPosX: curPosY;
    int end = isXChanged ? nextPosX : nextPosY;
    int x = 0;
    int y = 0;
    // 确定坐标是递增还是递减
    int change = end - start >= 0 ? 1 : -1;
    start += change;
    // 判断是吃子还是移动
    if (PositionMessage::position[nextPosX][nextPosY].isFilled) {
        // 吃子
        // 检查移动路径上是否有2个及以上棋子
        int cnt = 0;
        for (int i = start; i != end; i += change) {
            x = isXChanged ? i : curPosX;
            y = isXChanged ? curPosY : i;
            if (PositionMessage::position[x][y].isFilled) {
                ++cnt;
            }
        }
        // 2个就不行
        if (cnt != 1) {
            return false;
        }
    } else {
        // 移动
        for (int i = start; i != end; i += change) {
            x = isXChanged ? i : curPosX;
            y = isXChanged ? curPosY : i;
            if (PositionMessage::position[x][y].isFilled) {
                return false;
            }
        }
    }
    return true;
}
