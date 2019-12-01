#include "block.h"

int Block::getShapeIndex() const {
    return shapeIndex;
}

void Block::rotateCounterClockwise() {
    shapeIndex --;
    if (shapeIndex == -1) {
        shapeIndex = 3;
    }
}

void Block::rotateClockwise() {
    shapeIndex ++;
    if (shapeIndex == 4) {
        shapeIndex = 0;
    }
}

int Block::getLevel() const {
    return level;
}
