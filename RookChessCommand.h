/**
 * @author: 武连增
 */


#ifndef CHESS_ROOK_CHESS_COMMAND_H
#define CHESS_ROOK_CHESS_COMMAND_H
#include "AbstractChessCommand.h"

/**
 * 车棋子命令类，用于控制车移动
 * 继承与抽象棋子命令类
 */
class RookChessCommand : public AbstractChessCommand {
public:
    RookChessCommand(Chess chess);

    [[nodiscard]] bool isValid() const noexcept override;
};


#endif //CHESS_ROOK_CHESS_COMMAND_H
