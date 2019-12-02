#ifndef GRID_H
#define GRID_H
#include <vector>
#include <memory>
#include <map>
#include <string>

class Block;

class Cell;

class Grid {
    std::vector<std::vector<std::shared_ptr<Cell> > > cells;
    const int maxX;
    const int maxY;
    
public:
    Grid(int sizeX, int sizeY);
    void setBlockType(int xPos, int yPos, std::string type) const;
    void markCell(int xPos, int yPos) const;
    void unmarkAllCells() const;
    std::string getBlockType(int xPos, int yPos) const;
    bool isMarked(int xPos, int yPos) const;
    std::weak_ptr<Cell> getCell(int xPos, int yPos) const;
    void cleanOneRow(int rowNum);
    void clean();
    int getMaxX() const;
    int getMaxY() const;
};


#endif