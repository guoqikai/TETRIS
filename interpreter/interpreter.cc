#include <iostream>
#include "interpreter.h"
#include "operation.h"

Interpreter::Interpreter(std::vector<std::map<std::string, std::unique_ptr<Operation>>> defaultSet)
comSetMaxIndex(defaultSet.size())
{
    commandSet = std::move(defaultset);
    comSetIndex = 0;
}

std::unique_ptr<Operation> Interpreter::interpretCommand(std::string numCommand) const {
    int times = 0
    std::string command = "";
    for(std::string::size_type i = 0; i < numCommand.size(); ++i) {
        if (numCommand[i] >= '0' && numCommand[i] <= '9') {
            times += (i + 1) * (numCommand[i] - '0');
        }
        else {
            command = numCommand.substr(i);
        }
    }
    
    std::unique_ptr<Operation> op = nullptr;
    for(auto i = commandSet[comSetIndex].begin(); i != commandSet[comSetIndex].end(); ++i) {
        if ((i->first).find(command) == 0) {
            if (op == nullptr) {
                op = (i->second)->deepCopy();
                op->setTimes(times);
            }
            else {
                throw InvalidCommand{"find multiple matched command!"};
            }
        }
    }
    if (op == nullptr) {
        throw InvalidCommand{"cannot find command " + command};
    }
    return op;
}

void Interpreter::addCommand(std::string name, std::vector<std::string> commands) {
    if (commandSet[comSetIndex].count(name)) {
        throw InvalidCommand{"name already exist!"};
    }
    std::unique_ptr<Operation> op = nullptr;
    for (auto i = commands.rbegin(); i != commands.rend(); ++i ) {
        if (op == nullptr) {
            op = interpretCommand(command);
        }
        else {
            auto temp = interpretCommand(command);
            temp->setNext(op);
            op = std::move(temp);
        }
    }
    commandSet[commandSet].emplace(name, op);
}

void Interpreter::renameCommand(std::string oldName, std::string newName) {
    if (commandSet[comSetIndex].count(oldName)) {
        auto pair =  extract(oldName);
        pair.key() = newName;
        commandSet[comSetIndex].insert(std::move(pair));
    }
}

void Interpreter::notify() {
    
}
