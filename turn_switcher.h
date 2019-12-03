#ifndef TURN_SWITCHER_H
#define TURN_SWITCHER_H
#include <vector>
#include <memory>
#include "Observer"

class GameController;

class TurnSwitcher : public Observer {
    std::vector<GameController*> controllers;
    int next;
public:
    TurnSwitcher(std::vector<GameController*> controllers);
    void passNextOp(std::unique_ptr<Operation> &op);
    void notify(GameContrller &whoFrom) override;
    bool gameOver() const:
    void restart();
};

#endif
