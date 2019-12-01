#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <memory>
#include <map>
#include <vector>
#include <string>

class Operation;

class InvalidCommand {
    std::string info;
}

class Interpreter {
    std::vector<std::map<std::string, Operation>> &commandSet;
    const int comSetMaxIndex;
    int comSetIndex;
    
public:
    Interpreter(std::vector<std::map<std::string, Operation>> &defaultSet);
    unique_ptr<Operation> interpretCommand(std::string command) const;
    void addCommand(std::string command);
    void renameCommand(std::string oldName, std::string newName);
}


#endif
