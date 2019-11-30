#ifndef LBLOCK_H
#define LBLOCK_H
#include <vector>
#include "block.h"

struct LBlock: public Block {
    
    Vector<Vector<boolean>> getShape() const override;
};

#endif
