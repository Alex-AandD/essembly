#include "backend/include/bytecodeVisitor.hh"
#include "backend/include/instruction.hh"
#include "frontend/include/expr.hh"

namespace Essembly
{
    

BytecodeVisitor::BytecodeVisitor() {
}
BytecodeVisitor::~BytecodeVisitor() {
    for(size_t i = 0; i < instructions.size(); i++) {
        if (instructions[i]) {
            delete instructions[i];
            instructions[i] = nullptr;
        }
    }
}

void BytecodeVisitor::binaryExprHelper(BinaryExpr* expr) {
    Expr* lhs = expr->lhs.get();
    Expr* rhs = expr->rhs.get();
    lhs->acceptBytecodeVisitor(this);
    rhs->acceptBytecodeVisitor(this);
}

void BytecodeVisitor::visitBinaryExpr(BinaryExpr* expr) {
    return binaryExprHelper(expr);
}

void BytecodeVisitor::visitAddExpr(AddExpr* expr) {
    return visitBinaryExpr(expr); 
}

void BytecodeVisitor::visitSubExpr(SubExpr* expr) {
    return visitBinaryExpr(expr); 
}

void BytecodeVisitor::visitMulExpr(MulExpr* expr) {
    return visitBinaryExpr(expr); 
}

void BytecodeVisitor::visitDivExpr(DivExpr* expr) {
    return visitBinaryExpr(expr); 
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

void BytecodeVisitor::visitUnaryExpr(UnaryExpr* expr) {

}

void BytecodeVisitor::visitUnaryNotExpr(UnaryNotExpr* expr) {

}

void BytecodeVisitor::visitUnaryMinusExpr(UnaryMinusExpr* expr) {

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

} // Essembly