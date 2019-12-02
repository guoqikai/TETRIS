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
    return std::make_unique(ZBlock{});
}

void BlockFactory::setSequence(std::unique_ptr<std::vector<std::string> > &sequence) {
    BlockFactory::sequence = std::move(sequence);
}

std::unique_ptr<BlockFactory> BlockFactory::getRandomBlockFactory(std::unique_ptr<std::map<std::string, int> > const &map) {
    return std::make_unique(map);
}

std::unique_ptr<BlockFactory> BlockFactory::getNorandomBlockFactory() {
    return std::make_unique(NorandomBlockFactory(*BlockFactory::sequence));
}

