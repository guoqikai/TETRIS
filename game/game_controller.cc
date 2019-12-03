#include <map>
#include "game_controller.h"
#include "Operation.h"
#include "block.h"


GameController(BlockFactory &norandomFactory, DisplayController &display, int level, std::string name) {
    this->level = level;
    this->name = name;
    score = 0
    highestScore = 0
    this->norandomFactory = norandomFactory;
    dc = display;
    grid = Grid(11, 13);
    mc = MovementController(grid);
    inspector = GridInspector(grid);
    blockConfigurator = BlcokConfigurator{};
    postProcessor = PostProcessor{};
    setLevel();
    currenBlock = currentFactory.getBlock();
    dc.drawNextBlock(currenBlock->getShape);
}

void GameController::executeOperation(unique_ptr<Operation> const &operation) {
    Instruction ins = operation.getNextInstruction();
    bool turnComplete = false;
    while (ins != Instruction::Over) {
        if (ins == Instruction::Blind) {
            dc.blind();
        }
        else if (ins == Instruction::Heavy) {
            blockConfigurator.setExtraHeaviness(2);
        }
        if (ins == Instruction::IBlock) {
            std::unique_ptr<Block> nb = BlockFactory::getBlock("I");
            if (!mc.replaceBlock(nb)) {
                event = ControllerEvent::GameOver;
                notifyObservers();
                return;
            }
        }
        else if (ins == Instruction::JBlock) {
            std::unique_ptr<Block> nb = BlockFactory::getBlock("J");
            if (!mc.replaceBlock(nb)) {
                event = ControllerEvent::GameOver;
                notifyObservers();
                return;
            }
        }
        else if (ins == Instruction::LBlock) {
            std::unique_ptr<Block> nb = BlockFactory::getBlock("L");
            if (!mc.replaceBlock(nb)) {
                event = ControllerEvent::GameOver;
                notifyObservers();
                return;
            }
        }
        else if (ins == Instruction::OBlock) {
            std::unique_ptr<Block> nb = BlockFactory::getBlock("O");
            if (!mc.replaceBlock(nb)) {
                event = ControllerEvent::GameOver;
                notifyObservers();
                return;
            }
        }
        else if (ins == Instruction::SBlock) {
            std::unique_ptr<Block> nb = BlockFactory::getBlock("S");
            if (!mc.replaceBlock(nb)) {
                event = ControllerEvent::GameOver;
                notifyObservers();
                return;
            }
        }
        else if (ins == Instruction::ZBlock) {
            std::unique_ptr<Block> nb = BlockFactory::getBlock("Z");
            if (!mc.replaceBlock(nb)) {
                event = ControllerEvent::GameOver;
                notifyObservers();
                return;
            }
        }
        else if (ins == Instruction::TBlock) {
            std::unique_ptr<Block> nb = BlockFactory::getBlock("T");
            if (!mc.replaceBlock(nb)) {
                event = ControllerEvent::GameOver;
                notifyObservers();
                return;
            }
        }
        else if (ins == Instruction::Left) mc.moveLeft();
        else if (ins == Instruction::Right) mc.moveRight();
        else if (ins == Instruction::Clockwise) mc.rotate(true);
        else if (ins == Instruction::Counterclockwise) rotate(false);
        else if (ins == Instruction::Levelup) levelUp();
        else if (ins == Instruction::Leveldown) levelDown();
        else if (ins == Instruction::Down) {
            if (!mc.moveDown()) {
                turnComplete = true;
            }
        }
        else if (ins == Instruction::Drop) {
            mc.drop()
            turnComplete = true;
        }
    }
    event = ControllerEvent::Normal;
    notifyObservers();
    if (!mc.applyHeaviness()) {
        turnComplete = true;
    }
    if (turnComplete) {
        event = ControllerEvent::Switch;
        doAfterDrop();
        notifyObservers();
    }
}

void GameController::loadBlock() {
    dc.emptyNextBlock();
    mc.injectBlock(currentBlock);
    currentBlock = nullptr;
}

void GameController::doAfterDrop() {
    inspector.addBlock(mc.getBlock());
    postProcessor.executePostOperation(mc, inspector);
    inspector.updateGrid(mc);
    score += inspector.calculateScore(level);
    dc.updateCurrentScore(score);
    if (score > highestScore) {
        highestScore = score;
        dc.updateHighestScore(highestScore);
    }
    inspector.resetScore();
    dc.drawGrid(grid);
    currentBlock = std::move(currentFactory.getBlock());
    dc.drawGrid(currentBlock.getShape());
    if (inspector.triggeredAction()) {
        event = ControllerEvent::Action;
    }
}

void GameController::notifyObservers() {
    for (auto &ob : observers) ob->notify(*this);
}

void GameController::addObserver(Observer *ob) {
    observers.emplace_back(ob);
}

void GameController::restart() {
    cuurentScore = 0;
    grid.clean();
    dc.clean();
    inspector.reset();
    currenBlock = currentFactory.getBlock();
    dc.drawNextBlock(currenBlock->getShape);
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

ControllerEvent GameController::getEvent() {
    return event;
}

ControllerInfo GameController::getInfo() {
    return ControllerInfo{level, name};
}
