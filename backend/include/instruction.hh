#pragma once
#include "code.hh"

/* this is what I want */
/* let's say that I have something like 2 * 3 + 4 */
/* the instructions will be */
/*
    IPUSH 2
    IPUSH 3
    MUL

    IPUSH 4
    ADD
*/

/* 
should we push a value or an integer?
For now let's keep native types, then we will see
*/

namespace Essembly {
class DisassembleVisitor;


class Instruction {
public:
    CODE code;
public:
    Instruction(CODE);
    virtual ~Instruction();
    /* in the instruction object there will be a disassemble method for testing and debugging purposes */
    [[nodiscard]] virtual std::string acceptDisassembler(DisassembleVisitor* visitor) noexcept = 0;
};

class IADD_i: public Instruction {
public:
    IADD_i();
    ~IADD_i() override;
public:
    [[nodiscard]] std::string acceptDisassembler(DisassembleVisitor* visitor) noexcept override;
};

class ISUB_i: public Instruction {
public:
    ISUB_i();
    ~ISUB_i() override;
public:
    [[nodiscard]] std::string acceptDisassembler(DisassembleVisitor* visitor) noexcept override;
};

class IMUL_i: public Instruction {
public:
    IMUL_i();
    ~IMUL_i() override;
public:
    [[nodiscard]] std::string acceptDisassembler(DisassembleVisitor* visitor) noexcept override;
};

class IDIV_i: public Instruction {
public:
    IDIV_i();
    ~IDIV_i() override;
public:
    [[nodiscard]] std::string acceptDisassembler(DisassembleVisitor* visitor) noexcept override;
};

class NEG_LOGIC_i: public Instruction {
public:
    NEG_LOGIC_i();
    ~NEG_LOGIC_i() override;
public:
    [[nodiscard]] std::string acceptDisassembler(DisassembleVisitor* visitor) noexcept override;
};

class NEG_ARIT_i: public Instruction {
public:
    NEG_ARIT_i();
    ~NEG_ARIT_i() override;
public:
    [[nodiscard]] std::string acceptDisassembler(DisassembleVisitor* visitor) noexcept override;
};

class IPUSH_i: public Instruction {
public:
    int operand;
public:
    IPUSH_i(int);
    ~IPUSH_i() override;
public:
    [[nodiscard]] std::string acceptDisassembler(DisassembleVisitor* visitor) noexcept override;
};
}