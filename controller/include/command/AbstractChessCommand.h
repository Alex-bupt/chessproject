/**
 * @author 武连增
 */


#ifndef CHESS_ABSTRACT_CHESS_COMMAND_H
#define CHESS_ABSTRACT_CHESS_COMMAND_H

#include "chessboard.h"
#include "chessesmanager.h"

/**
 * WAITING_OTHERS宏是在开发过程中，其他项目组成员尚未提供API
 * 先用int定义的类型代替，省的IDE一直error
 **/
//#define WAITING_OTHERS
#ifndef WAITING_OTHERS
typedef AbstractChess *Chess;
#else
typedef int *Chess;
#endif // WAITING_OTHERS

/**
 * Controller采用了命令模式和模板方法模式
 */
class AbstractChessCommand {
public:
    AbstractChessCommand(Chess);

    virtual ~AbstractChessCommand() noexcept;

    /**
     * 移动棋子函数
     * @return 移动是否成功
     * @e 禁止覆写！
     **/
    bool move();

    /**
     * 撤销棋子函数
     * @e 禁止覆写！
     **/
    void undo();

    /**
    * 判断棋子能否移动到目标位置的算法<br>
    * @return true棋子能移动到目标位置，否则false
    **/
    [[nodiscard]] bool isAbleMoved() const noexcept;

    /**
     * 判断棋子移动是否超出边界<br>
     * 默认边界为棋盘边界，也可由子类覆写
     * @return true当棋子移动位置超出边界，否则false
     */
    [[nodiscard]] virtual bool isOutOfRanged() const noexcept;

    /**
     * 判断棋子移动是否符合规则<br>
     * 需要由子类自己定义
     * @return true棋子移动符合规则，否则false
     */
    [[nodiscard]] virtual bool isValid() const noexcept = 0;

    void setNextPos(int x, int y);

protected:
    int lastPosX;
    int lastPosY;
    int curPosX;
    int curPosY;
    int nextPosX;
    int nextPosY;

    Chess chess;
private:
    bool isVictory();
};

#endif //CHESS_ABSTRACT_CHESS_COMMAND_H
