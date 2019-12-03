#ifndef DISPLAY_CONTROLLER_H
#define DISPLAY_CONTROLLER_H
#include <vector>
#include <memory>

class Display;
class Grid;


class DisplayController {
    std::vector<std::shared_ptr<GraphicDisplay>> displays;
    int controllerId;

public:
    DisplayController(std::vector<std::shared_ptr<GraphicDisplay>> &displays, int id);
    void drawGrid((Grid &grid) const;
    void drawNextBlock(std::vector<std::vector<bool>> const shape);
    void emptyNextBlock();
    void blind();
    void updateCurrentScore(int current) const;
    void updateHighestScore(int highest) const;
};

#endif