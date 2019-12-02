#ifndef BLOCK_CONFIGURATOR_H
#define BLOCK_CONFIGURATOR_H
#include <memory>

class Block;

class BlockConfigurator {
    int heavinessLowerBound = 0;
    int heavinessUpperBound = 0;
    int extraHeaviness = 0;
    int proNormalBlock = 1;
    int proLimitTimeBlock = 0;
    int limitTimeBlockLowerBound = 0;
    int limitTimeBlockUpperBound = 0;


public:
    void configureBlock(std::unique_ptr<Block> const &block); 
    void setHeaviness(int heavinessLower, int heavinessUpper);
    void setExtraHeaviness(int extra);
    void setProNomal(int proNomal);
    void setProLimitTime(int proLimit);
    void setLimitRange(int lowerBound, int upperBound);

};

#endif
