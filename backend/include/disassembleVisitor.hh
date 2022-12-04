#pragma once
#include "instruction.hh"
/* this is going to be the disassemble visitor */
/* we use the visitor to keep the code cleaner */
/* do not clogg the instruction file with methods used mainly for debugging and testing */
/* use a different interface instead */

namespace Essembly {

class Instruction;

class DisassembleVisitor {
public:
    DisassembleVisitor();
    ~DisassembleVisitor();
public:
    /* binary expressions */
    [[nodiscard]] std::string disassembleIADD(IADD_i*) const noexcept;
    [[nodiscard]] std::string disassembleISUB(ISUB_i*) const noexcept;
    [[nodiscard]] std::string disassembleIMUL(IMUL_i*) const noexcept;
    [[nodiscard]] std::string disassembleIDIV(IDIV_i*) const noexcept;

    /* unary operations*/
    [[nodiscard]] std::string disassembleNEG_ARIT(NEG_ARIT_i*) const noexcept;
    [[nodiscard]] std::string disassembleNEG_LOGIC(NEG_LOGIC_i*) const noexcept;

    // push integers
    [[nodiscard]] std::string disassembleIPUSH(IPUSH_i*) const noexcept;
};
}