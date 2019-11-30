#ifndef TBLOCK_H
#define TBLOCK_H
#include <vector>
#include "block.h"

struct TBlock: public Block {
    
    Vector<Vector<boolean>> getShape() const override;
};

#endif
