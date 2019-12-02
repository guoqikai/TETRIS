#include "operation.h"

Instruction Operation::getNextInstruction() {
    if (!times_to_execute) {
        if (next != nullptr) {
            return next->getNextInstruction();
        }
        return Instruction::Over;
    }
    times_to_execute --;
    return current;
}

void Operation::setTimes(int times) {
    times_to_execute = times;
}

void Operation::setNext(std::unique_ptr<Operation> &nextOp) {
    next = std::move(nextOp);
}

std::unique_ptr<Operation> Operation::deepCopy() const {
    return std::make_unique(Operation{next.deepCopy(), times_to_execute, current});
}
