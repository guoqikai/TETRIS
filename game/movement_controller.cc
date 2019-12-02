#include "movement_controller.h"
#include "block.h"
#include "grid.h"

MovementController::MovementController(std::shared_ptr<Grid> &grid) {
    this->grid = grid;
}

boolean MovementController::applyHeaviness() const {
    int h = currentBlock->heaviness;
    while (h > 0) {
        if (!moveDown()) {
            return false;
        }
        h --;
    }
    return true;
}

boolean MovementController::moveDown() const {
    int xPos = currentBlock->xPos;
    int yPos = currentBlock->yPos;
    auto shape = currentBlock->getShape();
    if (!canPlaceBlock(shape, xPos, yPos + 1)) {
        return false;
    }
    eraseBlock(shape, xPos, yPos);
    placeBlcok(shape, xPos, yPos + 1);
    currentBlock->yPos ++;
    return true;
    
}

void MovementController::moveRight() const {
    int xPos = currentBlock->xPos;
    int yPos = currentBlock->yPos;
    auto shape = currentBlock->getShape();
    if (!canPlaceBlock(shape, xPos + 1, yPos)) {
        return;
    }
    eraseBlock(shape, xPos, yPos);
    placeBlcok(shape, xPos + 1, yPos);
    currentBlock->xPos ++;
}

void MovementController::moveLeft() const {
    int xPos = currentBlock->xPos;
    int yPos = currentBlock->yPos;
    if (xPos - 1 < 0) {
        return;
    }
    auto shape = currentBlock->getShape();
    if (!canPlaceBlock(shape, xPos - 1, yPos)) {
        return;
    }
    eraseBlock(shape, xPos, yPos);
    placeBlcok(shape, xPos - 1, yPos);
    currentBlock->xPos --;
}

void MovementController::rotate(bool clcokwise) const {
    int xPos = currentBlock->xPos;
    int yPos = currentBlock->yPos;
    auto shape = currentBlock->getShape();
    if (clockwise) {
        currentBlock->rotateClockwise();
    }
    else {
        currentBlock->rotateCounterClockwise();
    }
    if (!canPlaceBlock(currentBlock->getShape(), xPos, yPos)) {
        if (clockwise) {
            currentBlock->rotateCounterClockwise();
        }
        else {
            currentBlock->rotateClockwise();
        }
        return;
    }
    eraseBlock(shape, xPos, yPos);
    placeBlcok(currentBlock->getShape(), xPos, yPos);

}

bool MovementController::drop() const {
    bool canMoveDown = moveDown();
    bool hasMove = canMoveDown;
    while (canMoveDown) {
        canMoveDown = moveDown;
    }
    return hasMove;
}

void MovementController::eraseBlock(std::vector<std::vector<bool>> const &shape, int xPos, int yPos) const {
    for (int y = 0; y < shape.size; y++) { 
         for (int x = 0; x < shape[y].size(); x++) { 
             if (shape[y][x]) {
                 grid->unmarkCell(xPos + x, yPos - y);
             }
         } 
    } 
}

void MovementController::placeBlock(std::vector<std::vector<bool>> const &shape, int xPos, int yPos) const {
    for (int y = 0; y < shape.size; y++) { 
         for (int x = 0; x < shape[y].size(); x++) { 
             if (shape[y][x]) {
                 grid->markCell(xPos + x, yPos + y);
                 grid->setBlockType(xPos + x, yPos - y, currentBlock->getType());
             }
         } 
    }
}

bool MovementController::canPlaceBlock(std::vector<std::vector<bool>> const &shape, int xPos, int yPos) const {
    for (int y = 0; y < shape.size; y++) { 
         for (int x = 0; x < shape[y].size(); x++) { 
             if (shape[y][x] && grid->isMarked(x + xPos, yPos - y)) {
                 return false;
             }
         } 
    }
    return true;
}

bool MovementController::setBlock(std::unique_ptr<Block> &blcok, int xPos, int yPos) {
    int xPos = block.xPos;
    int yPos = block.yPos;
    auto shape = block.getShape();
    if (!canPlaceBlock(shape, xPos, yPos)) {
        return false
    }
    eraseBlock(shape, xPos, yPos);
    placeBlcok(shape, xPos, yPos);
    currentBlock = std::move(blcok);
    return true
}

std::unique_ptr<Block> MovementController::getBlock() {
    return currentBlock;
}