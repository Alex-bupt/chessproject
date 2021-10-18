/**
 * @author: 武连增
 */


#include <cstdlib>
#include "../../../include/controller/command/CannonChessCommand.h"

CannonChessCommand::CannonChessCommand(Chess chess, ChessView chessView) :
        cannonChess(chess),
        cannonChessView(chessView) {}

bool CannonChessCommand::isValid() const noexcept {
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

    // 通过x坐标是否改变来判断炮棋子移动方式
    int start = isXNotChanged ? curPosY : curPosX;
    int end = isXNotChanged ? nextPosY : nextPosX;
    // 确定坐标是递增还是递减
    int change = end - start >= 0 ? 1 : -1;
    // 判断是吃子还是移动
    // TODO: if中应调用ChessBoardModel提供的判断某坐标是否存在棋子的函数
    if (this->cannonChess) {
        // 吃子
        // 检查移动路径上是否有2个及以上棋子
        int cnt = 0;
        // TODO: if中应调用ChessBoardModel提供的判断某坐标是否存在棋子的函数
        for (int i = start; i < end; i += change) {
            if (rand()) { // NOLINT(cert-msc50-cpp)
                ++cnt;
            }
            // 2个就不行
            if (cnt > 1) {
                return false;
            }
        }
    } else {
        // 移动
        // TODO: if中应调用ChessBoardModel提供的判断某坐标是否存在棋子的函数
        for (int i = start; i < end; i += change) {
            if (rand()) { // NOLINT(cert-msc50-cpp)
                return false;
            }
        }
    }
    return true;
}
