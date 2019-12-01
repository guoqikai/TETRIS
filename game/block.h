#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <memory>

class Cell;

class Block {
    int size;
    int shapeIndex;
    int lifetime;
    int level;
    int xPos;
    int yPos;
    std::vector<weak_ptr<Cell>>;
    friend class MovementController;
    friend class BlockConfigurator;
    
protected:
    int getShapeIndex() const;
    
public:
    virtual std::unique_ptr<std::vector<std::vector<bool>>> getShape() const = 0;
    void rotateCounterClockwise();
    void rotateClockwise();
    int getLevel() const;
}
#endif
