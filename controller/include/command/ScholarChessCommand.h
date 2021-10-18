/**
 * @author: 武连增
 */


#ifndef CHESS_SCHOLAR_CHESS_COMMAND_H
#define CHESS_SCHOLAR_CHESS_COMMAND_H
#include "AbstractChessCommand.h"

/**
 * 士棋子命令类，用于控制士移动
 * 继承与抽象棋子命令类
 */
class ScholarChessCommand : public AbstractChessCommand {
public:
    ScholarChessCommand(Chess chess, ChessView chessView);
    [[nodiscard]] bool isValid() const noexcept override;
    // 士不能出九宫格，需要覆写边界范围
    [[nodiscard]] bool isOutOfRanged() const noexcept override;

private:
    Chess scholarChess;
    ChessView scholarChessView;
};


#endif //CHESS_SCHOLAR_CHESS_COMMAND_H
