#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H
#include <vector>
#include <memory>

class BlockFactory;
class MovementController;
class DisplayController;
class BlcokConfigurator;
class GridInspector;
class PostProcessor;
class Grid;
class Operation;

class GameController {
    
    ControllerState state;
    std::vector<Observer> observers;
    int level;
    const int maxLevel = 4;
    int score;
    int highestScore;
    shared_ptr<BlockFactory> blockFactory;
    shared_ptr<MovementController> movementController;
    shared_ptr<DisplayController> displayController;
    shared_ptr<Grid> grid;
    unique_ptr<BlcokConfigurator> blockConfigurator;
    unique_ptr<GridInspector> gridInspector;
    unique_ptr<PostProcessor> postProcessor;
    setLevel(int level);
    
public:
    GameController(shared_ptr<BlockFactory> factory,
                   shared_ptr<MovementController> movement,
                   shared_ptr<DisplayController> display,
                   shared_ptr<Grid> grid);
    
    executeOperation(unique_ptr<Operation> &operation);
    levelUp();
    levelDown();
}
