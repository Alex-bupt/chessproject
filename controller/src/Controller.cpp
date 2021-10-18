/**
 * @author: 武连增
 */

#include "../../include/controller/Controller.h"

// 这里可能会有bug
Controller* Controller::controller = new Controller(); // NOLINT(cert-err58-cpp)

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

Controller* Controller::getController() {
    return controller;
}
