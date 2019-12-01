#ifndef OPERATION_H
#define OPERATION_H
#include <memory>

enum class Instruction {Over};

class Operation {
    std::unique_ptr<Operation> next = nullptr;
    int times_to_exectute;
    Instruction current;
    
public:
    Instruction getNextInstruction();
    unique_ptr<Operation> deepCopy() const;
    void setTimes(int times);
    void setNext(unique_ptr<Operation> &nextOp);
}
#endif
