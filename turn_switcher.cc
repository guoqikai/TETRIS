#include <iostream>
#include "turn_switcher.h"
#include "game_controller.h"

TurnSwitcher::TurnSwitcher(std::vector<GameController*> controllers) {
    this->controllers = controllers;
    next = 0;
}

void TurnSwitcher::passNextOp(std::unique_ptr<Operation> &op) {
    controllers[next]->executeOperation(op);
}
void TurnSwitcher::notify(GameContrller &whoFrom) {
    if (whoFrom.getEvent() == ControllerEvent::Action || ControllerEvent::Switch) {
        next ++;
        if (next == controllers.size()) {
            next = 0;
        }
    }
    else if (whoFrom.getEvent() == ControllerEvent::GameOver) {
        std::cout << "Game over!! ";
        std::cout << whoFrom.getInfo.name + " lose" << std:endl;
        std::cout << "New game!!" << std:endl;
        for (auto &c : controllers) c->restart();
        next = 0;
    }
}

void TurnSwitcher::restart() {
    std::cout << "New game!!" << std:endl;
    for (auto &c : controllers) c->restart();
    next = 0;
}