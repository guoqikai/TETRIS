#ifndef BLOCK_FACTORY_H
#DEFINE BLOCK_FACTORY_H
#include <memory>
#include <string>

class Block;

class BlockFactory {
    
public:
    virtual unqiue_ptr<Block> getBlock() = 0;
    
    unqiue_ptr<Block> getBlock(std::string name) const;
}

#endif
