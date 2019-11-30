#include <vector>
#include "z_block.h"

Vector<Vector<boolean>> ZBlock::getShape() const {
    if (this->shapeIndex == 1 || this->shapeIndex == 3) {
        vector<boolean> rowOne1 {0, 0, 0, 0};
        vettor<boolean> rowTwo1 {0, 0, 0, 0};
        vettor<boolean> rowThree1 {1, 1, 0, 0};
        vector<boolean> rowFour1 {0, 1, 1, 0};
        vector<vector<boolean>> shapeOne {rowOne1, rowTwo1, rowThree1, rowFour1};
        return shapeOne;
    }
    else {
        vector<boolean> rowOne2 {0, 0, 0, 0};
        vettor<boolean> rowTwo2 {0, 1, 0, 0};
        vettor<boolean> rowThree2 {1, 1, 0, 0};
        vector<boolean> rowFour2 {1, 0, 0, 0};
        vector<vector<boolean>> shapeTwo {rowOne2, rowTwo2, rowThree2, rowFour2};
        return shapeTwo;
    }
}
