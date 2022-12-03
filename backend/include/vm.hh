#pragma once
#include "instruction.hh"
#include "value.hh"
#include "code.hh"
#include <functional>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Vm {
private:
    size_t ip;  /* instruction pointer pointing at the next instruction */
    size_t sp;  /* stack pointer pointing at the top of the stack */
    size_t retAddr; /* this is not an address but it is going to be the index to return to before destroying the stack frame*/
    size_t numInstructions; /* here we are going to store the total number of instruction (bytecode.size())*/
    std::vector<Value*> stack;  /* this is going to be our actual stack, on the stack there are only Value objects */
    std::vector<Instruction*> bytecode; /* this is going to be a sequence of instructions and operands */
    std::unordered_set<std::string> stringPool; /* this is going to be the place in memory where strings are stored */
    std::unordered_map<std::string, Value*> constPool; /* in this constant pool constants are going to be stored */
private:
    /* this is going to be the dispatch map */
    std::unordered_map<CODE, std::function<void()>> dispatchMap;
public: /* constructors and destructors */
    Vm();
    ~Vm();
    /* in the destructor you have to destroy the values inside the constPool */
    /* destroy everything on the stack */
private: /* these are some private utils methods */
    inline void advanceIp() { ip++; }
    [[nodiscard]] inline CODE readCode() { return static_cast<CODE>(bytecode[ip]->code); }
    void printStack(); /* print the current state of the stack */
private:

    [[nodiscard]] IntValue* ipop();
    void ipush(IntValue* value);
    void iadd();
    void isub();
    void imul();
    void idiv();
public:
    void interpret() {
        while (!atEnd()) {
            CODE code =  readCode();
            std::function<void()> operation = dispatchMap[code]; /* choose the correct action given the code */
            operation();
            advanceIp();
        }
    }
    [[nodiscard]] inline const bool atEnd() { return ip >= numInstructions; }
};