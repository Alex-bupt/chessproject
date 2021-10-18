/**
 * @author: 武连增
 */


#ifndef CHESS_ELEPHANT_CHESS_COMMAND_H
#define CHESS_ELEPHANT_CHESS_COMMAND_H
#include "AbstractChessCommand.h"

/**
 * 象棋子命令类，用于控制象移动
 * 继承与抽象棋子命令类
 */
class ElephantChessCommand : public AbstractChessCommand{
public:
    ElephantChessCommand(Chess chess, ChessView chessView);
    [[nodiscard]] bool isValid() const noexcept override;
    // 象不能过河，需要覆写边界范围
    [[nodiscard]] bool isOutOfRanged() const noexcept override;

private:
    Chess elephantChess;
    ChessView elephantChessView;
};


#endif //CHESS_ELEPHANT_CHESS_COMMAND_H
