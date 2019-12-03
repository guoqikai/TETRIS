#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H
#include <vector>
#include <memory>
#include "post_processor.h"
#include "block_factory.h"
#include "movement_controller.h"
#include "grid_inspector.h"
#include "display_controller.h"
#include "block_configutator.h"
#include "post_processor.h"
#include "grid.h"

class Operation;
class Block;

enum class ControllerEvent {GameOver, Switch, Action, Normal};

struct ControllerInfo {
    int level;
    std::string name;
}

class GameController {
    
    std::vector<Observer*> observers;
    ControllerEvent event;
    std::string name
    int level;
    const int maxLevel = 4;
    int score;
    int highestScore;
    BlockFactory currentFactory;
    BlockFactory norandomFactory;
    DisplayController dc;
    MovementController mc;
    GridInspector inspector;
    Grid grid;
    BlcokConfigurator blockConfigurator;
    PostProcessor postProcessor;
    std::unique_ptr<Block> currenBlock;
    void setLevel();
    void doAfterDrop();
    
public:
    GameController(BlockFactory &norandomFactory, DisplayController &display, int level, std::string name);
    void loadBlock(); 
    void executeOperation(unique_ptr<Operation> &operation);
    void levelUp();
    void levelDown();
    void restart();
    void notifyObervers();
    void addObserver(Observer *ob);
    ControllerEvent getEvent();
    ControllerInfo getInfo();
}

#endif
