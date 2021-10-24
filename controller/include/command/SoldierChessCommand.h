/**
 * @author: 武连增
 */


#ifndef CHESS_SOLDIER_CHESS_COMMAND_H
#define CHESS_SOLDIER_CHESS_COMMAND_H
#include "AbstractChessCommand.h"

/**
 * 兵棋子命令类，用于控制兵移动
 * 继承与抽象棋子命令类
 */
class SoldierChessCommand : public AbstractChessCommand {
public:
    SoldierChessCommand(Chess chess);

    [[nodiscard]] bool isValid() const noexcept override;
};

#endif //CHESS_SOLDIER_CHESS_COMMAND_H
