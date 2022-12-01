#pragma once
#include "code.hh"

class Instruction {
public:
    CODE code;
public:
    Instruction(CODE);
    virtual ~Instruction();
};

class IADD_i: public Instruction {
public:
    IADD_i();
    ~IADD_i() override;
};

class ISUB_i: public Instruction {
public:
    ISUB_i();
    ~ISUB_i() override;
};

class IMUL_i: public Instruction {
public:
    IMUL_i();
    ~IMUL_i() override;
};

class IDIV_i: public Instruction {
public:
    IDIV_i();
    ~IDIV_i() override;
};

class IPUSH_i: public Instruction {
public:
    int operand;
public:
    IPUSH_i(int);
    ~IPUSH_i() override;
};