#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H
#include <memory>

class MovementController;
class GridInspector;
class Grid;

class PostProcessor {
    dropBlockAfter = false;
    initialPosX = 5;
    initialPosY = 0;

public:
    void executePostOperation(std::unique_ptr<MovementController> &mc, std::unique_ptr<GridInspector> &gi, std::unique_ptr<Grid> &grid);
    void setDropBlockAfter(bool enable);
    void setInitialPosition(int posX, int posY);
};


#endif