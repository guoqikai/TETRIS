#include "post_processor.h"
#include "block_factory.h"
#include "movement_controller.h"
#include "grid_inspector.h"

class Block;

void PostProcessor::executePostOperation(std::unique_ptr<MovementController> &mc, std::unique_ptr<GridInspector> &gi) {
    if (dropBlockAfter && timesLeft == 0) {
        std::unique_ptr<Block> block = BlockFactory::getBlock("*");
        if (mc->injectBlock(&blcok, initialPosX, initialPosY)) {
            mc->dropBlock();
            gi->addBlock(mc->getBlock());
            gi->updateGrid();
        }
        timesLeft = period; 
    } else {
        timesLeft --;
    }
}

void PostProcessor::setDropBlockAfter(bool enable) {
    dropBlockAfter = enable
}

void PostProcessor::setInitialPosition(int posX, int posY) {
    initialPosX = posX;
    initialPosY = posY;
}

void PostProcessor::setPeriod(int period) {
    this->period = period;
    timesLeft = period;
}