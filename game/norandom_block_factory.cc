#include "norandom_block_factory.h"
#include "block.h"

NorandomBlockFactory::NorandomBlockFactory(std::vector<std::string> sequence) {
    this->sequence = sequence;
    nextIndex = 0;
}

unqiue_ptr<Block> NorandomBlockFactory::getBlock() {
    std::string name = vector[nextIndex];
    nextIndex ++;
    if (nextIndex == sequence.size()) {
        nextIndex = 0;
    }
    return getBlock(name);
}


