#include "random_block_factory.h"
#include "block.h";

RandomBlockFactory::RandomBlockFactory(unqiue_ptr<std::map<std::string, float>> &map) {
    for (auto i = map.begin(); it != map.end(); ++i) {
        sumP += i->second;
    }
    probabilityMap = std::move(map);
}

void RandomBlockFactory::setSeed(int seed) {
    this->seed = seed;
}

unqiue_ptr<Block> RandomBlockFactory::getBlock() const {
    int randVal = srand(seed) % sumP;
    int sum = 0;
    for (auto i = probabilityMap.begin(); it != probabilityMap.end(); ++i) {
        if (sum + i->second > randVal) {
            return getBlock(i->first);
        }
    }
    return nullptr;
}
