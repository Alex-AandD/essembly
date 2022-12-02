#include "backend/include/bytecodeVisitor.hh"
#include "backend/include/instruction.hh"
#include "frontend/include/expr.hh"

BytecodeVisitor::BytecodeVisitor(std::vector<Instruction*>& instr): instructions(instr) { }
BytecodeVisitor::~BytecodeVisitor() {
    for(size_t i = 0; i < instructions.size(); i++) {
        delete instructions[i];
    }
}

void BytecodeVisitor::binaryExprHelper(BinaryExpr* expr) {
    Expr* lhs = expr->lhs;
    Expr* rhs = expr->rhs;
    lhs->acceptBytecodeVisitor(this);
    rhs->acceptBytecodeVisitor(this);
}

void BytecodeVisitor::visitBinaryExpr(BinaryExpr* expr) {
}

void BytecodeVisitor::visitIAddExpr(IAddExpr* expr) {
    binaryExprHelper(expr);
    /* add the add instruction at the end */
    instructions.push_back(new IADD_i());
}

void BytecodeVisitor::visitISubExpr(ISubExpr* expr) {
    binaryExprHelper(expr);
    /* add the sub instruction at the end */
    instructions.push_back(new ISUB_i());
}

void BytecodeVisitor::visitIMulExpr(IMulExpr* expr) {
    binaryExprHelper(expr);
    /* add the sub instruction at the end */
    instructions.push_back(new IMUL_i());
}

void BytecodeVisitor::visitIDivExpr(IDivExpr* expr) {
    binaryExprHelper(expr);
    /* add the sub instruction at the end */
    instructions.push_back(new IDIV_i());
}

/* TODO: implement bytecode generator for unary expressions */
static inline Instruction* chooseFinalBinaryInstruction(TT type) {
    switch (type)
    {
    case TT::PLUS:
        return new IADD_i();

    case TT::MINUS:
        return new ISUB_i();

    case TT::SLASH:
        return new IDIV_i();

    case TT::TIMES:
        return new IMUL_i();

    default:
        break;
    }
}

// TODO: #5 add support for unary expression @Alex-AandD
static inline Instruction* chooseFinalUnaryExpr(TT type) {
}

void BytecodeVisitor::visitIntExpr(IntExpr* expr) {
    /* here we push an integer onto the stack */
    /* the value of the expression is going to be the operand */
    /* so the instruction at the end is going to look like this */
    /* IPUSH operand */
    instructions.push_back(new IPUSH_i(expr->value));
}