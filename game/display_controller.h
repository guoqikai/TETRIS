#ifndef DISPLAY_CONTROLLER_H
#define DISPLAY_CONTROLLER_H
#include <vector>
#include <memory>

class GraphicDisplay;
class TextDisplay;
class Grid;


class DisplayController {
    GraphicDisplay *graphic;
    TextDisplay *text;
    int controllerId;

public:
    DisplayController(GraphicDisplay *graphic, TextDisplay *text, int id);
    void drawGrid((Grid *grid) const;
    void drawNextBlock(std::vector<std::vector<bool>> const shape);
    void emptyGrid();
    void emptyNextBlock();
    void updateCurrentScore(int current) const;
    void updateHighestScore(int highest) const;
};

#endif