#include "backend/include/disassembleVisitor.hh"
#include "backend/include/instruction.hh"
#include "backend/include/code.hh"
#include <string>
/* when we disassemble an instruction we need to provide: */
/* CODE    [OPERANDS]   line_number */
/* for now I have no idea how to provide the number we'll support that later */
//TODO: #9 add line number support @Alex-AandD

namespace Essembly {
DisassembleVisitor::DisassembleVisitor() { }
DisassembleVisitor::~DisassembleVisitor() { }

[[nodiscard]] static std::string zeroOpInstructionHelper(Instruction* instruction) noexcept {
    std::string codeString = CodetoString(instruction->code);
    return codeString;
}

/* binary expressions */
[[nodiscard]] std::string DisassembleVisitor::disassembleIADD(IADD_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

[[nodiscard]] std::string DisassembleVisitor::disassembleISUB(ISUB_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

[[nodiscard]] std::string DisassembleVisitor::disassembleIMUL(IMUL_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

[[nodiscard]] std::string DisassembleVisitor::disassembleIDIV(IDIV_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

/* unary expressions */
[[nodiscard]] std::string DisassembleVisitor::disassembleNEG_LOGIC(NEG_LOGIC_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

[[nodiscard]] std::string DisassembleVisitor::disassembleNEG_ARIT(NEG_ARIT_i* instruction) const noexcept {
    return zeroOpInstructionHelper(instruction);
}

/* primary expressions */
[[nodiscard]] std::string DisassembleVisitor::disassembleIPUSH(IPUSH_i* instruction) const noexcept {
    std::string codeString = CodetoString(instruction->code);
    std::string operand = std::to_string(instruction->operand);
    return codeString + "   " + operand ;
}
}