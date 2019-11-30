#ifndef JBLOCK_H
#define JBLOCK_H
#include <vector>
#include "block.h"

struct JBlock: public Block {
    
    Vector<Vector<boolean>> getShape() const override;
};

#endif
