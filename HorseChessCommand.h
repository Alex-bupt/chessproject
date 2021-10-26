/**
 * @author: 武连增
 */


#ifndef CHESS_HORSE_CHESS_COMMAND_H
#define CHESS_HORSE_CHESS_COMMAND_H
#include "AbstractChessCommand.h"

/**
 * 马棋子命令类，用于控制马移动
 * 继承与抽象棋子命令类
 */
class HorseChessCommand : public AbstractChessCommand{
public:
    HorseChessCommand(Chess chess);

    [[nodiscard]] bool isValid() const noexcept override;
};


#endif //CHESS_HORSE_CHESS_COMMAND_H
