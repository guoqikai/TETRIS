#ifndef DISPLAY_CONTROLLER_H
#define DISPLAY_CONTROLLER_H
#include <vector>
#include <map>
#include <memory>

class GraphicDisplay;
class TextDisplay;
class Grid;


class DisplayController {
    std::shared_ptr<GraphicDisplay> graphic;
    std::shared_ptr<TextDisplay> text;
    int controllerId;

public:
    DisplayController(std::shared_ptr<GraphicDisplay> &graphic, std::shared_ptr<TextDisplay> &text, int id);
    void drawGrid((std::shared_ptr<Grid> const &grid) const;
    void drawNextBlock(std::vector<std::vector<bool>> const &shape);
    void updateCurrentScore(int current) const;
    void updateHighestScore(int highest) const;
};

#endif