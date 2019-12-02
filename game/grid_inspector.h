#ifndef GRID_INSPECTOR_H
#define GRID_INSPECTOR_H
#include <vector>
#include <map>
#include <memory>

class MovementController;
class Block;
struct Cell;

class GridInspector {
    std::map<std::unique_ptr<Block>, std::vector<std::weak_ptr<Cell>>> tackedBlocks;
    int numLinesRemoved;
    int score;

public:
    void updateGrid(std::unique_ptr<MovementController> &mc,  std::shared_ptr<Grid> grid);
    void addBlock(std::unique_ptr<Block> &block);
    int calculateScore(int currentLevel) const;
    bool triggeredAction() const;
    void reset();
};

#endif