#ifndef NORANDOM_BLOCK_FACTORY_H
#define NORANDOM_BLOCK_FACTORY_H
#include <string>
#include <memory>
#include <vector>
#include "block_factory.h"

class NorandomBlockFactory : public BlockFactory {
    std::vector<std::string> sequence;
    int nextIndex;
    
public:
    NorandomBlockFactory(std::vector<std::string> sequence);
    unqiue_ptr<Block> getBlock() override;
}
#endif

