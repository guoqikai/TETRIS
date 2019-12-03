#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H
#include <memory>

class MovementController;
class GridInspector;

class PostProcessor {
    bool dropBlockAfter = false;
    int initialPosX = 5;
    int initialPosY = 0;
    int period = 5;
    int timesLeft;

public:
    void executePostOperation(std::unique_ptr<MovementController> &mc, std::unique_ptr<GridInspector> &gi);
    void setDropBlockAfter(bool enable);
    void setInitialPosition(int posX, int posY);
    void setPeriod(int period);
};


#endif