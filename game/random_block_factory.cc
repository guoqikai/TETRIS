#include <cstdlib>
#include <assert.h>
#include "random_block_factory.h"
#include "block.h"

RandomBlockFactory::RandomBlockFactory(std::map<std::string, int> const map) {
    for (auto i = map.begin(); i != map.end(); ++i) {
        assert(i->second > 0);
        sumP += i->second;
    }
    probabilityMap = std::move(map);
}

std::unique_ptr<Block> RandomBlockFactory::getBlock() {
    int randVal = rand() % sumP;
    int sum = 0;
    for (auto i = probabilityMap.begin(); i != probabilityMap.end(); ++i) {
        if (sum + i->second > randVal) {
            return BlockFactory::getBlock(i->first);
        }
    }
}
