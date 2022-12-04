#include "backend/include/vm.hh"
#include <cmath>
#define KB 1024
#define MB 1024 * 1000
#define STACK_SIZE 8 * MB

namepace Essembly {
Vm::Vm(): ip(0), sp(0), retAddr(0) { 
    /* reserve some space in advance for the stack */
    /* initialize the dispatch map */ 
    dispatchMap = {
        {CODE::IADD, [this]  () { iadd(); }},
        {CODE::ISUB,  [this] ()  { isub(); }},
        {CODE::IMUL,  [this] ()  { imul(); }},
        {CODE::IDIV,  [this] ()  { idiv(); } },
        {CODE::IPUSH, [this] (IntValue* val) { ipush(val); }},
    }
}
Vm::~Vm() { 
    /* first delete everything onto the stack */
    for (size_t i = 0; i < stack.size(); i++) {
        auto ptr = stack[i];
        if (ptr) {
            delete stack[i];
        }
    }
    
    /* second delete everything into the pool */
    for(auto it = constPool.begin(); it != constPool.end(); it++) {
        delete it->second;
    }

    /* now delete every instruction */
    for (size_t i = 0; bytecode.size(); i++) {
        delete bytecode[i];
    }
}

void Vm::ipush(IntValue* value) {
    /* push the value onto the stack */
    stack[sp] = value;
    sp++;
    /* NOTE the stack pointer points always to the next value on the stack */
}

[[nodiscard]] IntValue* Vm::ipop() {
    /* pop an integer from the stack */
    if (sp == 0) {
        throw("the stack is empty, cannot pop anything");
    }
    /* first decrease the stack pointer */
    sp--;
    /* and then return the value*/
    IntValue* value = static_cast<IntValue*>(stack[sp]);
    return value;
}

void Vm::iadd() {
    /* current instruction */
    Instruction* instr = bytecode[ip];
    /* pop rhs and lhs and push their sum onto the stack */
    IntValue* rhs = ipop(); 
    IntValue* lhs = ipop(); 
    IntValue* finalValue = rhs->value + lhs->value;
    ipush(finalValue);
}

void Vm::isub() {
    /* current instruction */
    Instruction* instr = bytecode[ip];
    /* pop rhs and lhs and push their sum onto the stack */
    IntValue* rhs = ipop(); 
    IntValue* lhs = ipop(); 
    IntValue* finalValue = lhs->value - rhs->value;
    ipush(finalValue);
}

void Vm::imul() {
    /* current instruction */
    Instruction* instr = bytecode[ip];
    /* pop rhs and lhs and push their sum onto the stack */
    IntValue* rhs = ipop(); 
    IntValue* lhs = ipop(); 
    IntValue* finalValue = lhs->value * rhs->value;
    ipush(finalValue);
}

void Vm::idiv() {
    /* current instruction */
    Instruction* instr = bytecode[ip];
    /* pop rhs and lhs and push their sum onto the stack */
    IntValue* rhs = ipop(); 
    IntValue* lhs = ipop(); 
    IntValue* finalValue = floor(lhs->value / rhs->value);
    ipush(finalValue);
}
}