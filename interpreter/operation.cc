#include operation.h

Instruction Operation::getNextInstruction() {
    if (!times_to_exectute) {
        if (next != nullptr) {
            return next->getNextInstruction();
        }
        return Instruction::Over;
    }
    times_to_exectute --;
    return current;
}

void Operation::setTimes(int times) {
    this->times = times;
}

void Operation::setNext(unique_ptr<Operation> &nextOp) {
    next = std::move(nextOp);
}

unique_ptr<Operation> Operation::deepCopy() {
    return make_unique(Operation{nextOp.deepCopy(), times, ins});
}
