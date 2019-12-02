#ifndef BLOCK_FACTORY_H
#define BLOCK_FACTORY_H
#include <memory>
#include <string>
#include <vector>
#include <map>

class Block;

class BlockFactory {
    static std::unique_ptr<std::vector<std::string> > sequence = nullptr;
    
public:
    virtual std::unique_ptr<Block> getBlock() = 0;
    static void setSequence(std::unique_ptr<std::vector<std::string> > &sequence);
    static std::unique_ptr<BlockFactory> getRandomBlockFactory(std::unique_ptr<std::map<std::string, int> > const &map);
    static std::unique_ptr<BlockFactory> getNorandomBlockFactory();
    static std::unique_ptr<Block> getBlock(std::string name);
};

#endif
