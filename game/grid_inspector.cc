#include "grid_inspector.h"
#include "grid.h"
#include "block.h"

GridInspector::GridInspector(Grid &grid) : grid{grid} {
    tackedBlocks = {};
    numRowsRemoved = 0;
    score = 0;
}

void GridInspector::updateGrid(MovementController &mc) {
    int removed = cleanFilledRow();
    numRowsRemoved += removed;
    cleanRemovedBlock();
    while (removed) {
        blockDropped = true;
        while (blockDropped) {
            blockDropped = dropAllBlock(mc);
        }
        removed = cleanFilledRow();
        numRowsRemoved += removed;
        cleanRemovedBlock();
    }
}

int GridInspector::cleanFilledRow() const {
    int rowRemoved = 0;
    for (int y = 3; y < grid.getMaxY(); y++) {
        allFilled = true;
        for (int x = 0; x < grid.getMaxX(); x++) {
            if (grid.getBlockType(x, y) != "") {
                allFilled = false;
                break;
            }
        }
        if (allFilled) {
            grid.cleanOneRow(y);
            rowRemoved ++;
        }
    }
    return rowRemoved;
}

bool GridInspector::dropAllBlock(MovementController &mc) {
    bool blockDropped = false;
    for ( auto i = tackedBlocks.begin(); i != tackedBlocks.end(); ++i) {
        mc.setCurrentBlock(i->first);
        if (mc.dropBlock()) {
            blockDropped = true;
        }
        i->first = std::move(mc.getBlock());
    }
    return blockDropped;
}

void GridInspector::cleanRemovedBlock() {
    for (auto i = tackedBlocks.begin(); i != tackedBlocks.end(); ++i) {
        bool allFreed = true;
        for (auto cell = (i->second)->begin(); cell != (i->second)->end(); ++cell) {
            if ((*cell).lock()) {
                allFreed = false;
                break;
            } 
        }
        if (allFreed) {
            int rs = ((i->first)->getLevel()) + 1
            score += rs * rs;
            tackedBlocks.erase(i);
        }
    }
}

void GridInspector::addBlock(std::unique_ptr<Block> &block) {
    std::vector<std::weak_ptr<Cell>> cells;
    auto shape = block->getShape();
     for (int y = 0; y < shape.size; y++) { 
         for (int x = 0; x < shape[y].size(); x++) { 
             if (shape[y][x]) {
                 cells.emplace_back(getCell(block->xPos + x,  block->yPos - y));
             }
         } 
    } 
    tackedBlocks.emplace(std::move(block), cells);
}

int GridInspector::calculateScore(int currentLevel) const {
    return (numRowsRemoved + currentLevel) * (numRowsRemoved + currentLevel) + score;
}

bool GridInspector::triggeredAction() const {
    return numRowsRemoved > 1;
}

void GridInspector::resetScore() {
    numLinesRemoved = 0;
    score = 0;
}

void GridInspector::ckean() {
    resetScore();
    tackedBlocks = {};
}