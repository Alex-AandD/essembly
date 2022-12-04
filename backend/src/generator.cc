#include "backend/include/generator.hh"
#include "backend/include/bytecodeVisitor.hh"
#include "frontend/include/expr.hh"
#include "backend/include/instruction.hh"
#include "backend/include/disassembleVisitor.hh"
#include <iostream>


namespace Essembly {

Generator::Generator(u_ptrExpr& _AST): 
    AST(std::move(_AST)), 
    bytecodeVisitor(std::make_unique<BytecodeVisitor>()), 
    disassembleVisitor(std::make_unique<DisassembleVisitor>())
{
    // reserve some space for all the instructions
    instructions.reserve(100000);
}
Generator::~Generator() { }

/* now here we need to generate some good code */
/* pass the statements to the */

/* TODO: #7 add statements to the parser, the generator and the visitors @Alex-AandD*/
void Generator::generateBytecode() {
    /* make the AST accept the visitor */
    /* then the visitor is going to choose the correct method thanks to the vtable */
    AST->acceptBytecodeVisitor(bytecodeVisitor.get());
    instructions = std::move(bytecodeVisitor->instructions);
}

// TODO: #10 disassemble using an external file @Alex-AandD
void Generator::disassemble() const noexcept {
    /* print the instructions in a civil way */
    /* loop through all the instructions, the index is going to be the instruction number */
    /* then print the instruction and the operands */
    size_t len = instructions.size();
    for (size_t i = 0; i < len; i++) {
        auto instruction = instructions[i];
        std::string stringInstruction = instruction->acceptDisassembler(disassembleVisitor.get());
        std::cout << std::hex << i << "     " <<
        stringInstruction << '\n';
    }
}
}