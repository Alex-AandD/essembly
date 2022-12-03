#include "backend/include/instruction.hh"
#include "backend/include/code.hh"
#include "backend/include/disassembleVisitor.hh"

Instruction::Instruction(CODE t): code(t) { }
Instruction::~Instruction() { }

IADD_i::IADD_i(): Instruction(CODE::IADD) { }
IADD_i::~IADD_i() { }

[[nodiscard]] std::string IADD_i::acceptDisassembler(DisassembleVisitor* visitor) noexcept {
    return visitor->disassembleIADD(this);
}

ISUB_i::ISUB_i(): Instruction(CODE::ISUB) { }
ISUB_i::~ISUB_i() { }

[[nodiscard]] std::string ISUB_i::acceptDisassembler(DisassembleVisitor* visitor) noexcept {
    return visitor->disassembleISUB(this);
}

IMUL_i::IMUL_i(): Instruction(CODE::IMUL) { }
IMUL_i::~IMUL_i() { }

[[nodiscard]] std::string IMUL_i::acceptDisassembler(DisassembleVisitor* visitor) noexcept {
    return visitor->disassembleIMUL(this);
}

IDIV_i::IDIV_i(): Instruction(CODE::IDIV) { }
IDIV_i::~IDIV_i() { }
[[nodiscard]] std::string IDIV_i::acceptDisassembler(DisassembleVisitor* visitor) noexcept {
    return visitor->disassembleIDIV(this);
}

IPUSH_i::IPUSH_i(int op): Instruction(CODE::IPUSH), operand(op) { }
IPUSH_i::~IPUSH_i() { }

[[nodiscard]] std::string IPUSH_i::acceptDisassembler(DisassembleVisitor* visitor) noexcept {
    return visitor->disassembleIPUSH(this);
}