/**
 * @author: 武连增
 */


#ifndef CHESS_MARSHAL_CHESS_COMMAND_H
#define CHESS_MARSHAL_CHESS_COMMAND_H
#include "AbstractChessCommand.h"

/**
 * 将棋子命令类，用于控制将移动
 * 继承与抽象棋子命令类
 */
class MarshalChessCommand : public AbstractChessCommand{
public:
    MarshalChessCommand(Chess chess);
    [[nodiscard]] bool isValid() const noexcept override;
    // 将不能出九宫格，需要覆写边界范围
    [[nodiscard]] bool isOutOfRanged() const noexcept override;
};


#endif //CHESS_MARSHAL_CHESS_COMMAND_H
