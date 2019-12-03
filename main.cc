#include <map>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <ifstream>
#include <cstdlib>
#include "operation.h"
#include "interpreter.h"
#include "game_controller.h"
#include "graphics_display.h"
#include "text_display.h"
#include "display_controller.h"
#include "norandom_block_factory.h"

std::vector<std::string> getSequence(std::string path) {
    string blcok;
    ifstream file;
    std::vector<std::string> seq = {}
    file.open (path);
    if (!file.is_open()) return;
    while (file >> word) {
        seq.emplace_back(word);
    }
    return seq;
}


int main(int argc, char *argv[]) {
    std::string path1 = "sequence1.txt";
    std::string path2 = "sequence2.txt";
    int startLevel = 0
    bool textOnly = false
    std::vector< std::shared_ptr<TextDisplay>> displays = {std::make_shared(TextDisplay())};
    for (int i = 1; i < argc; i ++) {
        std::string arg = argc[i];
        if (arg == "-text") {
            textOnly = true;
        }
        else {
            std::string next = argc[i + 1];
            if (arg == "-seed") {
                srand(std::stoi(next));
            }
            else if (arh == "-scriptfile1") {
                path1 = next;
            }
            else if (arh == "-scriptfile2") {
                path2 = next;
            }
            else {
                startLevel = std::stoi(next);
            }
        }
    }
    NorandomBlockFactory f1 = NorandomBlockFactory(getSequence(path1);
    NorandomBlockFactory f2 = NorandomBlockFactory(getSequence(path2);
    if (!textOnly) {
        displays.emplace_back(std::make_shared(GraphicsDisplay()));
    }
    DisplayController dc1 = DisplayController(displays, 0);
    DisplayController dc2 = DisplayController(displays, 1);
    GameController gc1 = GameController(f1, dc1, startLevel, "player 1");
    GameController gc2 = GameController(f1, dc1, startLevel, "player 2");
    std::vector<std::map<std::string, >>operations = {
        {   
            {"left", make_shared<Operation>(Instruction::Left)}, {"right", make_shared<Operation>(Instruction::Right)}, 
            {"Down", make_shared<Operation>(Instruction::Down)}, {"clockwise", make_shared<Operation>(Instruction::Clockwise)},
            {"counterclockwise", make_shared<Operation>(Instruction::Counterclockwise)}, {"drop", make_shared<Operation>(Instruction::drop)}, 
            {"levelup", make_shared<Operation>(Instruction::Levelup)}, {"leveldown", make_shared<Operation>(Instruction::Leveldown)},
            {"I", make_shared<Operation>(Instruction::IBlock)}, {"J", make_shared<Operation>(Instruction::JBlock)}, {"L", make_shared<Operation>(Instruction::LBlock)}
        },
        {
            {"blind", make_shared<Operation>(Instruction::Blind)}, {"heavy", make_shared<Operation>(Instruction::Heavy)}, 
            {"I", make_shared<Operation>(Instruction::IBlock)}, {"J", make_shared<Operation>(Instruction::JBlock)},
            {"L", make_shared<Operation>(Instruction::LBlock)}, {"O", make_shared<Operation>(Instruction::OBlock)}, 
            {"S", make_shared<Operation>(Instruction::SBlock)}, {"Z", make_shared<Operation>(Instruction::ZBlock)},
            {"T", make_shared<Operation>(Instruction::TBlock)}
    }};
    Interpreter interpreter = Interpreter(operations);
    TurnSwitcher ts = TurnSwitcher({&gc1, &gc2});
    gc1.addObserver(&interpreter);
    gc1.addObserver(&ts);
    gc2.addObserver(&interpreter);
    gc2.addObserver(&ts);
    std::string next;
    while (std::cin>>next) {
        if (next == "restart") {
            ts.restart();
        }
        else if (next == "force") {
            std::cin>>next;
            if (next.size()!= 1) {
                std::cout << "Plase enter a block name!!";
            }
        }
        else {
            std::unqiue_ptr<Operation> nextOP = interpreter(interpretCommand);
            ts.passNextOp(nextOP);
        }

    }

}   
