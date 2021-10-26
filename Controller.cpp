/**
 * @author: 武连增
 */

#include "Controller.h"
#include <cassert>

// 这里可能会有bug
Controller* Controller::controller = new Controller(); // NOLINT(cert-err58-cpp)
std::stack<AbstractChessCommand*> Controller::commandsStack;

Controller::~Controller() {
    destroyCommands();
}

std::stack<AbstractChessCommand *> Controller::getCommandsStack() {
    return commandsStack;
}

void Controller::destroyCommands() {
    while (!commandsStack.empty()) {
        delete commandsStack.top();
        commandsStack.pop();
    }
}

Controller Controller::getController() {
    return *controller;
}


void Controller::moveChess(ChessType chessType, Chess chess, int nextPosX, int nextPosY) {
    auto command = createChessCommand(chessType, chess);
    command->setNextPos(nextPosX, nextPosY);
    if (command->move()) {
        commandsStack.push(command);
        return;
    }
    // 若移动失败则命令作废，需要释放掉
    delete command;
}

AbstractChessCommand *Controller::createChessCommand(int chessType, Chess chess) {
    AbstractChessCommand *command = nullptr;
    switch (chessType) {
        case Cannon:
            command = new CannonChessCommand(chess);
            break;
        case Elephant:
            command = new ElephantChessCommand(chess);
            break;
        case Horse:
            command = new HorseChessCommand(chess);
            break;
        case Marshal:
            command = new MarshalChessCommand(chess);
            break;
        case Rook:
            command = new RookChessCommand(chess);
            break;
        case Scholar:
            command = new ScholarChessCommand(chess);
            break;
        case Soldier:
            command = new SoldierChessCommand(chess);
            break;
        default:
            assert(false);
    }
    return command;
}

void Controller::regretChess() {
    auto top = commandsStack.top();
    top->undo();
    delete top;
    commandsStack.pop();
}
