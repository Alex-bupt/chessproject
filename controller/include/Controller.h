/**
 * @author: 武连增
 */

#ifndef CHESS_CONTROLLER_H
#define CHESS_CONTROLLER_H

#include "command/AbstractChessCommand.h"

/**
 * 采用单例模式
 */
class Controller {
public:
    static Controller* getController();

    /**
     * 获得储存命令的栈
     * @return 储存命令的栈
     **/
    static std::stack<AbstractChessCommand *> getCommandsStack();

    ~Controller();

private:
    Controller() = default;

    static Controller* controller;
    /**
     * delete所有new出来的AbstractChessCommand子类指针
     */
    static void destroyCommands();
    static std::stack<AbstractChessCommand *> commandsStack;
};

#endif //CHESS_CONTROLLER_H
