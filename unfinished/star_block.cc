#include <vector>
#include "block.h"

std::string StarBlock::getType() const {
    return "*";
}

Vector<Vector<boolean>> StarBlock::getShape() const {
    vector<boolean> rowOne {0, 0, 0, 0};
    vettor<boolean> rowTwo {0, 0, 0, 0};
    vettor<boolean> rowThree {0, 0, 0, 0};
    vector<boolean> rowFour {1, 0, 0, 0};
    vector<vector<boolean>> shape {rowOne, rowTwo, rowThree, rowFour};
    return shape;
}

