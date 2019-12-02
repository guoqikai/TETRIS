#ifndef BLOCK_FACTORY_H
#define BLOCK_FACTORY_H
#include <memory>
#include <string>
#include <map>

class Block;

class BlockFactory {
    
public:
    virtual std::unique_ptr<Block> getBlock() = 0;
    static BlockFactory getRandomBlockFactory(std::map<std::string, int> const &map);
    static std::unique_ptr<Block> getBlock(std::string name);
};

#endif
