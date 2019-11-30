#ifndef IBLOCK_H
#define IBLOCK_H
#include <vector>
#include "block.h"

struct IBlock: public Block {
    
    Vector<Vector<boolean>> getShape() const override;
};

#endif
