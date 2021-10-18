/**
 * @author: 武连增
 */


#include <cmath>
#include <MarshalChessCommand.h>

MarshalChessCommand::MarshalChessCommand(Chess chess, ChessView chessView) :
        AbstractChessCommand(chess, chessView) {}

bool MarshalChessCommand::isValid() const noexcept {
    int nextPosX = 0, nextPosY = 0;
    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    if (this->chess->team == ChessBoard::position[nextPosX][nextPosY].character) {
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
    int team = chess->team;
    nextPosY -= (!team) * 7;
    return nextPosX >= 3 && nextPosX <= 5 && nextPosY >= 0 && nextPosY <= 2;
}
