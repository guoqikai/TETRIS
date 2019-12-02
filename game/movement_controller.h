#ifndef MOVEMENT_CONTROLLER_H
#define MOVEMENT_CONTROLLER_H
#include <memory>
#include <vector>

class Block;
class Grid;

class MovementController {
    std::shared_ptr<Grid> grid;
    std::unique_ptr<Block> currentBlock;


public:
    MovementController(std::shared_ptr<Grid> &grid);
    bool applyHeaviness() const;
    bool moveDown() const;
    void moveRight() const;
    void moveLeft() const;
    void rotate(bool clcokwise) const;
    bool drop() const;
    void placeBlock(std::vector<std::vector<bool>> const &shape, int xPos, int yPos) const;
    void eraseBlock(std::vector<std::vector<bool>> const &shape, int xPos, int yPos) const;
    bool canPlaceBlock(std::vector<std::vector<bool>> const &shape, int xPos, int yPos) const;
    bool setBlock(std::unique_ptr<Block> &blcok, int xPos, int yPos);
    std::unique_ptr<Block> getBlock();
};

#endif

