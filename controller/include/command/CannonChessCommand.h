/**
 * @author: 武连增
 */


#ifndef CHESS_CANNON_CHESS_COMMAND_H
#define CHESS_CANNON_CHESS_COMMAND_H
#include "AbstractChessCommand.h"

/**
 * 炮棋子命令类，用于控制炮移动
 * 继承与抽象棋子命令类
 */
class CannonChessCommand : public AbstractChessCommand{
public:
    CannonChessCommand(Chess chess, ChessView chessView);
    [[nodiscard]] bool isValid() const noexcept override;

private:
    Chess cannonChess;
    ChessView cannonChessView;
};


#endif //CHESS_CANNON_CHESS_COMMAND_H
