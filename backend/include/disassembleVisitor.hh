#pragma once
#include "instruction.hh"
/* this is going to be the disassemble visitor */
/* we use the visitor to keep the code cleaner */
/* do not clogg the instruction file with methods used mainly for debugging and testing */
/* use a different interface instead */

class Instruction;

class DisassembleVisitor {
public:
    [[nodiscard]] std::string disassembleIADD(IADD_i*) const noexcept;
    [[nodiscard]] std::string disassembleISUB(ISUB_i*) const noexcept;
    [[nodiscard]] std::string disassembleIMUL(IMUL_i*) const noexcept;
    [[nodiscard]] std::string disassembleIDIV(IDIV_i*) const noexcept;
    [[nodiscard]] std::string disassembleIPUSH(IPUSH_i*) const noexcept;
};