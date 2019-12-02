#include "norandom_block_factory.h"
#include "random_block_factory.h"
#include "block_factory.h"
#include "block.h"

std::unique_ptr<Block> BlockFactory::getBlock(std::string name) {
    if (name == "I") {
        return std::make_unique(IBlock{});
    }
    if (name == "J") {
        return std::make_unique(JBlock{});
    }
    if (name == "L") {
        return std::make_unique(LBlock{});
    }
    if (name == "O") {
        return std::make_unique(OBlock{});
    }
    if (name == "S") {
        return std::make_unique(SBlock{});
    }
    if (name == "T") {
        return std::make_unique(TBlock{});
    }
    if (name == "Z") {
        return std::make_unique(ZBlock{});
    }
    return std::make_unique(StarBlock{});
}

BlockFactory BlockFactory::getRandomBlockFactory(std::map<std::string, int> const &map) {
    return RandomBlockFactory(map);
}

