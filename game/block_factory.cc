#include "block_factory.h"
#include "block.h"

unqiue_ptr<Block> BlockFactory::getBlock(std::string name) const {
    return Block.getBlock(name);
}
