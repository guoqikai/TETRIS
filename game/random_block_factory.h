#ifndef RANDOM_BLOCK_FACTORY_H
#define RANDOM_BLOCK_FACTORY_H
#include <cstdlib>
#include <string>
#include <memory>
#include <map>
#include "block_factory.h"

class RandomBlockFactory : public BlockFactory {
    std::unqiue_ptr<std::map<std::string, int>> probabilityMap;
    int seed;
    int sumP;
    
public:
    RandomBlockFactory(unqiue_ptr<std::map<std::string, float>> &map);
    unqiue_ptr<Block> getBlock() override const;
}
#endif
