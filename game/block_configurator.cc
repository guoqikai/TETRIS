#include <cstdlib>
#include "block_configurator.h"
#include <assert.h>

void BlcokConfigurator::configureBlock(std::unique_ptr<Block> const &block) {
    assert(proNormalBlock || proLimitTimeBlock);
    int block->heaviness = heavinessLowerBound + extraHeaviness;
    if (heavinessUpperBound != heavinessLowerBound) {
        block->heaviness += rand() % (heavinessUpperBound - heavinessLowerBound);
    }
    extraHeaviness = 0;
    block->lifeTime = -1;
    int randLifeTime = limitTimeBlockLowerBound;
    if (limitTimeBlockUpperBound != limitTimeBlockLowerBound) {
        randLifeTime += rand() % (limitTimeBlockUpperBound - limitTimeBlockLowerBound);
    }
    int normalOrLimit = rand() % (proNormalBlock + proLimitTimeBlock);
    if (normalOrLimit < proLimitTimeBlock) {
        block->lifeTime = randLifeTime;
    }

}

void BlockConfigurator::setHeaviness(int heavinessLower, int heavinessUpper) {
    assert(heavinessLower <= heavinessUpper)
    this->heavinessLowerBound = heavinessLower;
    this->heavinessUpperBound = heavinessUpper
}
void BlockConfigurator::setExtraHeaviness(int extra) {
    extraHeaviness = extra;
}
void BlockConfigurator::setProNomal(int proNomal) {
    proNormalBlock = proNomal;
}
void BlcokConfigurator::setProLimitTime(int proLimit) {
    proLimitTimeBlock = proLimit;

}
void BlcokConfigurator::setLimitRange(int lowerBound, int upperBound) {
    assert(lowerBound <= upperBound)
    limitTimeBlockLowerBound = lowerBound;
    limitTimeBlockUpperBound = upperBound;
}

void BlcokConfigurator::setLevel(int level) {
    this->level = level;
}