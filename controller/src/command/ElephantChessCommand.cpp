/**
 * @author: 武连增
 */


#include <cmath>
#include <ElephantChessCommand.h>

ElephantChessCommand::ElephantChessCommand(Chess chess) :
        AbstractChessCommand(chess) {}

bool ElephantChessCommand::isValid() const noexcept {
    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    if (this->chess->team == ChessBoard::position[nextPosX][nextPosY].character) {
        return false;
    }

    int xOffset = nextPosX - curPosX;
    int yOffset = nextPosY - curPosY;
    unsigned uXOffset = abs(xOffset);
    unsigned uYOffset = abs(yOffset);
    // 检查是否走田字
    if (uXOffset != 2 || uYOffset != 2) {
        return false;
    }
    // 检查是否别象眼
    xOffset >>= 1;
    yOffset >>= 1;
    // 判断的坐标：curPosX + xOffset, curPosY + yOffset
    if (ChessBoard::position[curPosX + xOffset][curPosY + yOffset].isFilled) {
        return false;
    }
    return true;
}

bool ElephantChessCommand::isOutOfRanged() const noexcept {
    int nextPosX = 0, nextPosY = 0;
    int team = chess->team;
    nextPosY -= (!team) * 5;
    return nextPosX >= 0 && nextPosX <= 8 && nextPosY >= 0 && nextPosY <= 4;
}