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

void GameController::executeOperation(unique_ptr<Operation> &operation) {
    Instruction ins = operation.getNextInstruction();
    while (ins != Instruction::Over) {
        if (ins == Instruction::Blind) {
            dc.blind();
        }
        else if (ins == Instruction::Heavy) {
            blockConfigurator.setExtraHeaviness(2);
        }
        else {
            if (currenBlock != nullptr) {
                dc.emptyNextBlock();
                mc.injectBlock(currenBlock);
            }
            if (ins == Instruction::IBlock) {
            
            }
            else if (ins == Instruction::JBlock) {
            
            }
            else if (ins == Instruction::LBlock) {
            
            }
            else if (ins == Instruction::OBlock) {
            
            }
            else if (ins == Instruction::SBlock) {
            
            }
            else if (ins == Instruction::ZBlock) {
            
            }
            else if (ins == Instruction::TBlock) {
            
            }
            else if (ins == Instruction::Left) {
            
            }
            else if (ins == Instruction::Right) {
            
            }
            else if (ins == Instruction::Down) {
            
            }
            else if (ins == Instruction::Clockwise) {
            
            }
            else if (ins == Instruction::Counterclockwise) {
            
            }
            else if (ins == Instruction::Drop) {
            
            }
            else if (ins == Instruction::Levelup) {
            
            }
            else if (ins == Instruction::Leveldown) {
            }
        }
    }
}

void GameController::startNewTurn() {

}

void GameController::restart() {
    
}

void GameController::levelUp() {
    if (level < maxLevel) {
        level ++;
        setLevel();
    }
}
void GameController::levelDown() {
    if (level > 0) {
        level --;
        setLevel();
    }
}

void GameController::setLevel() {
    switch(level) {
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
