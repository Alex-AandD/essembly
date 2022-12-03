#include "backend/include/generator.hh"
#include "backend/include/bytecodeVisitor.hh"
#include "frontend/include/expr.hh"
#include "backend/include/instruction.hh"
#include <iostream>


Generator::Generator(Expr* _AST): bytecodeVisitor(new BytecodeVisitor(instructions)), AST(_AST)  {
    /* reserve some space for all the instructions */
    instructions.reserve(10000);
}
Generator::~Generator() {
    if (bytecodeVisitor) {
        delete bytecodeVisitor;
        bytecodeVisitor = nullptr;
    }

    if (disassembleVisitor) {
        delete disassembleVisitor;
        disassembleVisitor = nullptr;
    }

    /* TODO: #6 turn this loop into a lambda @Alex-AandD */
    for (size_t i = 0; i < instructions.size(); i++) {
        if (instructions[i]) {
            delete instructions[i];
            instructions[i] = nullptr;
        }
    }

    if (AST) {
        delete AST;
        AST = nullptr;
    }
}

/* now here we need to generate some good code */
/* pass the statements to the */

/* TODO: #7 add statements to the parser, the generator and the visitors @Alex-AandD*/
void Generator::generateBytecode() {
    /* make the AST accept the visitor */
    /* then the visitor is going to choose the correct method thanks to the vtable */
    AST->acceptBytecodeVisitor(bytecodeVisitor);
}

// TODO: #10 disassemble using an external file @Alex-AandD
void Generator::disassemble() const noexcept {
    /* print the instructions in a civil way */
    /* loop through all the instructions, the index is going to be the instruction number */
    /* then print the instruction and the operands */
    size_t len = instructions.size();
    for (size_t i = 0; i < len; i++) {
        auto instruction = instructions[i];
        std::string stringInstruction = instruction->acceptDisassembler(disassembleVisitor);
        std::cout << std::hex << i << "     " <<
        stringInstruction << '\n';
    }
}
