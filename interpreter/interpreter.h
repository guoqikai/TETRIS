#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "observer.h"

class Operation;

class InvalidCommand {
    std::string info;
};

class Interpreter : public Observer {
    std::vector<std::map<std::string, std::shared_ptr<Operation>>> commandSet;
    const int comSetMaxIndex;
    int comSetIndex;
    
public:

    Interpreter(std::vector<std::map<std::string,std::unique_ptr<Operation>>> defaultSet);
    std::unique_ptr<Operation> interpretCommand(std::string command) const;
    void addCommand(std::string command);
    void renameCommand(std::string oldName, std::string newName);
    void notify(GameContrller &whoFrom) override;
};

#endif
