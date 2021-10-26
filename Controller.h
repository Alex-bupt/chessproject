/**
 * @author: 武连增
 */

#ifndef CHESS_CONTROLLER_H
#define CHESS_CONTROLLER_H

#include "ChessCommand.h"
#include <stack>

enum ChessType {
    Cannon,
    Elephant,
    Horse,
    Marshal,
    Rook,
    Scholar,
    Soldier
};

/**
 * 采用单例模式
 */
class Controller {
public:
    static Controller getController();

    /**
     * 将象棋移动到目标位置，若不符合移动条件则保持原位
     *
     * @param chessType 象棋类型，请使用定义好的常量
     * @param chess 象棋模型
     * @param nextPosX 下一步的X坐标
     * @param nextPosY 下一步的纵坐标
     */
    void moveChess(ChessType chessType, Chess chess, int nextPosX, int nextPosY);

    /**
     * 悔棋
     */
    void regretChess();

    /**
     * 获得储存命令的栈
     * @return 储存命令的栈
     **/
    std::stack<AbstractChessCommand *> getCommandsStack();

    ~Controller();

private:
    static std::stack<AbstractChessCommand *> commandsStack;

    static Controller* controller;

    Controller() = default;

    /**
     * delete所有new出来的AbstractChessCommand子类指针
     */
    static void destroyCommands();

    /**
     * 根据象棋的类型创建对应的指令
     *
     * @param chessType 象棋类型
     * @param chess 对应象棋Model
     * @return 创建的指令
     */
    static AbstractChessCommand *createChessCommand(int chessType, Chess chess);
};

#endif //CHESS_CONTROLLER_H
