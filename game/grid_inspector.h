#ifndef GRID_INSPECTOR_H
#define GRID_INSPECTOR_H
#include <vector>
#include <map>
#include <memory>

class MovementController;
class Block;
class Grid;
struct Cell;

class GridInspector {
    std::map<std::unique_ptr<Block>, std::vector<std::weak_ptr<Cell>>> tackedBlocks;
    Grid &grid;
    int numRowsRemoved;
    int score;
    int cleanFilledRow() const;
    bool dropAllBlock();
    void cleanRemovedBlock();

public:
    GridInspector(Grid &grid);
    void updateGrid(MovementController &mc);
    void addBlock(std::unique_ptr<Block> &block);
    int calculateScore(int currentLevel) const;
    bool triggeredAction() const;
    void resetScore();
    void clean();
};

#endif