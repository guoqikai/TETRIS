#include "norandom_block_factory.h"
#include "block.h"

NorandomBlockFactory::NorandomBlockFactory(std::vector<std::string> sequence) {
    this->sequence = std::move(sequence);
    nextIndex = 0;
}

std::unique_ptr<Block> NorandomBlockFactory::getBlock() {
    std::string name = sequence[nextIndex];
    nextIndex ++;
    if (nextIndex == sequence.size()) {
        nextIndex = 0;
    }
    return BlockFactory::getBlock(name);
}


