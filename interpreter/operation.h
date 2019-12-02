#ifndef OPERATION_H
#define OPERATION_H
#include <memory>

enum class Instruction {Over};

class Operation {
    std::unique_ptr<Operation> next;
    int times_to_execute;
    Instruction current;
    
public:
    Instruction getNextInstruction();
    std::unique_ptr<Operation> deepCopy() const;
    void setTimes(int times);
    void setNext(std::unique_ptr<Operation> &nextOp);
};
#endif
