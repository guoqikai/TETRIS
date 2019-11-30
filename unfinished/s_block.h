#ifndef SBLOCK_H
#define SBLOCK_H
#include <vector>
#include "block.h"

struct SBlock: public Block {
    
    Vector<Vector<boolean>> getShape() const override;
};

#endif
