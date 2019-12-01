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
    shared_ptr<DisplayController> displayController;
    unique_ptr<BlcokConfigurator> blockConfigurator;
    shared_ptr<MovementController> movementController;
    shared_ptr<PostProcessor> postProcessor;
    unique_ptr<GridInspector> gridInspector;
    shared_ptr<Grid> grid;
    
    setLevel(int level);
    
public:
    GameController(shared_ptr<BlockFactory> factory,
                   shared_ptr<DisplayController> display,
                   shared_ptr<PostProcessor> postProcessor;
                   shared_ptr<BlcokConfigurator> blockConfigurator;
                   );
    
    executeOperation(unique_ptr<Operation> &operation);
    levelUp();
    levelDown();
}
#endif
