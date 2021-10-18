/**
 * @author: 武连增
 */


#include "../../../include/controller/command/RookChessCommand.h"

RookChessCommand::RookChessCommand(Chess chess, ChessView chessView) :
        rookChess(chess),
        rookChessView(chessView) {}

bool RookChessCommand::isValid() const noexcept {
    int nextPosX = 0, nextPosY = 0;
    bool isXNotChanged = nextPosX - curPosX != 0;

    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
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
    // TODO: if中应调用ChessBoardModel提供的判断某坐标是否存在棋子的函数
    for (int i = start; i < end; i += change) {
        if (this->rookChess) {
            return false;
        }
    }
    return true;
}
