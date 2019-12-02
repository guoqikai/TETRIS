#ifndef RANDOM_BLOCK_FACTORY_H
#define RANDOM_BLOCK_FACTORY_H
#include <string>
#include <memory>
#include <map>
#include "block_factory.h"

class RandomBlockFactory : public BlockFactory {
    std::map<std::string, int> probabilityMap;
    int sumP;
    
public:
    RandomBlockFactory(std::map<std::string, int> &map);
    std::unique_ptr<Block> getBlock() override;
    void setSeed(int seed);
};
#endif
