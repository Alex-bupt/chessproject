/**
 * @author: 武连增
 */


#include "../../../include/controller/command/HorseChessCommand.h"
#include <cmath>

HorseChessCommand::HorseChessCommand(Chess chess, ChessView chessView) :
        horseChess(chess),
        horseChessView(chessView) {}

bool HorseChessCommand::isValid() const noexcept {
    int nextPosX = 0, nextPosY = 0;

    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    int xOffset = nextPosX - curPosX;
    int yOffset = nextPosY - curPosY;

    unsigned uXOffset = abs(xOffset);
    unsigned uYOffset = abs(yOffset);
    // 判断是否走日字
    if (!xOffset || !yOffset) {
        return false;
    }
    if (uXOffset + uYOffset != 3) {
        return false;
    }

    // 判断是否硌马腿
    xOffset >>= 1;
    yOffset >>= 1;
    // TODO: if中应调用ChessBoardModel提供的判断某坐标是否存在棋子的函数
    // 判断的坐标：curPosX + xOffset, curPosY + yOffset
    if (this->horseChess) {
        return false;
    }
    return true;
}
