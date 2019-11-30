#ifndef OBLOCK_H
#define OBLOCK_H
#include <vector>
#include "block.h"

struct OBlock: public Block {
    
    Vector<Vector<boolean>> getShape() const override;
};

#endif
