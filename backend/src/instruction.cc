#include "backend/include/instruction.hh"
#include "backend/include/code.hh"

Instruction::Instruction(CODE t): code(t) { }
Instruction::~Instruction() { }

IADD_i::IADD_i(): Instruction(CODE::IADD) { }
IADD_i::~IADD_i() { }

ISUB_i::ISUB_i(): Instruction(CODE::ISUB) { }
ISUB_i::~ISUB_i() { }

IMUL_i::IMUL_i(): Instruction(CODE::IMUL) { }
IMUL_i::~IMUL_i() { }

IDIV_i::IDIV_i(): Instruction(CODE::IDIV) { }
IDIV_i::~IDIV_i() { }

IPUSH_i::IPUSH_i(int op): Instruction(CODE::IPUSH), operand(op) { }
IPUSH_i::~IPUSH_i() { }