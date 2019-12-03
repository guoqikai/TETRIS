#include <vector>
#include "block.h"

std::string OBlock::getType() const {
    return "O";
}


Vector<Vector<boolean>> OBlock::getShape() const {
    vector<boolean> rowOne {0, 0, 0, 0};
    vettor<boolean> rowTwo {0, 0, 0, 0};
    vettor<boolean> rowThree {1, 1, 0, 0};
    vector<boolean> rowFour {1, 1, 0, 0};
    vector<vector<boolean>> shape {rowOne, rowTwo, rowThree, rowFour};
    return shape;
}
