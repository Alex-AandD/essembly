#include "backend/include/disassembleVisitor.hh"
#include "backend/include/instruction.hh"
#include <string>
/* when we disassemble an instruction we need to provide: */
/* CODE    [OPERANDS]   line_number */
/* for now I have no idea how to provide the number we'll support that later */
//TODO: #9 add line number support @Alex-AandD

DisassembleVisitor::DisassembleVisitor() { }
DisassembleVisitor::~DisassembleVisitor() { }

[[nodiscard]] static std::string zeroOpIntructionHelper(Instruction* instruction) noexcept {
    std::string codeString = CodetoString(instruction->code);
    return codeString;
}

[[nodiscard]] std::string DisassembleVisitor::disassembleIADD(IADD_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

[[nodiscard]] std::string DisassembleVisitor::disassembleISUB(ISUB_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

[[nodiscard]] std::string DisassembleVisitor::disassembleIMUL(IMUL_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

[[nodiscard]] std::string DisassembleVisitor::disassembleISUB(ISUB_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

[[nodiscard]] std::string DisassembleVisitor::disassembleIPUSH(IPUSH_i* instruction) const noexcept {
    std::string codeString = CodetoString(instruction->code);
    std::string operand = std::to_string(instruction->operand);
    return codeString + "   " + operand ;
}
