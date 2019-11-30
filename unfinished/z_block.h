#ifndef ZBLOCK_H
#define ZBLOCK_H
#include <vector>
#include "block.h"

struct ZBlock: public Block {
    
    Vector<Vector<boolean>> getShape() const override;
};

#endif
