#include <vector>
#include "t_block.h"

Vector<Vector<boolean>> TBlock::getShape() const {
    if (this->shapeIndex == 1) {
        vector<boolean> rowOne1 {0, 0, 0, 0};
        vettor<boolean> rowTwo1 {0, 0, 0, 0};
        vettor<boolean> rowThree1 {1, 1, 1, 0};
        vector<boolean> rowFour1 {0, 1, 0, 0};
        vector<vector<boolean>> shapeOne {rowOne1, rowTwo1, rowThree1, rowFour1};
        return shapeOne;
    }
    else if (this->shapeIndex == 2) {
        vector<boolean> rowOne2 {0, 0, 0, 0};
        vettor<boolean> rowTwo2 {0, 1, 0, 0};
        vettor<boolean> rowThree2 {1, 1, 0, 0};
        vector<boolean> rowFour2 {0, 1, 0, 0};
        vector<vector<boolean>> shapeTwo {rowOne2, rowTwo2, rowThree2, rowFour2};
        return shapeTwo;
    }
    else if (this->shapeIndex == 3) {
        vector<boolean> rowOne3 {0, 0, 0, 0};
        vettor<boolean> rowTwo3 {0, 0, 0, 0};
        vettor<boolean> rowThree3 {0, 1, 0, 0};
        vector<boolean> rowFour3 {1, 1, 1, 0};
        vector<vector<boolean>> shapeThree {rowOne3, rowTwo3, rowThree3, rowFour3};
        return shapeThree;
    }
    else{
        vector<boolean> rowOne4 {0, 0, 0, 0};
        vettor<boolean> rowTwo4 {1, 0, 0, 0};
        vettor<boolean> rowThree4 {1, 1, 0, 0};
        vector<boolean> rowFour4 {1, 0, 0, 0};
        vector<vector<boolean>> shapeFour {rowOne4, rowTwo4, rowThree4, rowFour4};
        return shapeFour;
    }
}
