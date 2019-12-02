#include <map>
#include "game_controller.h"
#include "Operation.h"
#include "block.h"


GameController(BlockFactory &norandomFactory, DisplayController &display, int level) {
    this->level = level;
    score = 0
    highestScore = 0
    this->norandomFactory = norandomFactory;
    dc = display;
    grid = Grid(11, 13);
    mc = MovementController(&grid);
    inspector = GridInspector(&grid);
    blockConfigurator = BlcokConfigurator{};
    postProcessor = PostProcessor{};
    setLevel();
    std::unique_ptr<Block> currenBlock = currentFactory.getBlock();
    dc.drawNextBlock(currenBlock->getShape);
}

void executeOperation(unique_ptr<Operation> &operation) {
    
}

void levelUp() {
    if (level < maxLevel) {
        level ++;
        setLevel();
    }
}
void levelDown() {
    if (level > 0) {
        level --;
        setLevel();
    }
}

void setLevel() {
    switch(leve;) {
        case 1 : {
            std::map<std::string, int> pMap = {{"S", 1}, {"Z", 1}, {"I", 2}, {"J", 2}, {"L", 2}, {"O", 2}, {"T", 2}};
            currentFactory = BlockFactory::getRandomBlockFactory(pMap);
            blockConfigurator.setHeaviness(0, 0);
            blockConfigurator.setProNomal(1);
            blockConfigurator.setProLimitTime(0);
            postProcessor.setDropBlockAfter(false);
            break;
        }       
        case 2 : {
            std::map<std::string, int> pMap = {{"S", 1}, {"Z", 1}, {"I", 1}, {"J", 1}, {"L", 1}, {"O", 1}, {"T", 1}};
            currentFactory = BlockFactory::getRandomBlockFactory(pMap);
            blockConfigurator.setHeaviness(0, 0);
            blockConfigurator.setProNomal(1);
            blockConfigurator.setProLimitTime(0);
            postProcessor.setDropBlockAfter(false);
            break;
        }
        case 3 : {
            std::map<std::string, int> pMap = {{"S", 2}, {"Z", 2}, {"I", 1}, {"J", 1}, {"L", 1}, {"O", 1}, {"T", 1}};
            currentFactory = BlockFactory::getRandomBlockFactory(pMap);
            blockConfigurator.setHeaviness(1, 1);
            blockConfigurator.setProNomal(1);
            blockConfigurator.setProLimitTime(0);
            postProcessor.setDropBlockAfter(false);
            break;
        }

        case 4 : {
            std::map<std::string, int> pMap = {{"S", 2}, {"Z", 2}, {"I", 1}, {"J", 1}, {"L", 1}, {"O", 1}, {"T", 1}};
            currentFactory = BlockFactory::getRandomBlockFactory(pMap);
            blockConfigurator.setHeaviness(1, 1);
            blockConfigurator.setProNomal(1);
            blockConfigurator.setProLimitTime(0);
            postProcessor.setDropBlockAfter(true);
            postProcessor.setPeriod(5);
        }
        default: {
            currentFactory = norandomFactory;
            blockConfigurator.setHeaviness(0, 0);
            blockConfigurator.setProNomal(1);
            blockConfigurator.setProLimitTime(0);
            postProcessor.setDropBlockAfter(false);
        }
    }
}
