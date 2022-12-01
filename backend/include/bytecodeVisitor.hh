#pragma once
#include <vector>

class BinaryExpr;
class IntExpr;
class UnaryExpr;
class Instruction;

/* this visitor is going to generate raw and unoptimized bytecode */
class BytecodeVisitor {
    std::vector<Instruction*> instructions;
public:
    BytecodeVisitor();
    ~BytecodeVisitor();
private:
    /* these are going to be some helpers to create bytecode */
    void binaryExprHelper(BinaryExpr* expr);
public:
    /* all the binary expressions */
    void visitBinaryExpr(BinaryExpr* expr);
    void visitIAddExpr(IAddExpr* expr);
    void visitISubExpr(ISubExpr* expr);
    void visitIMulExpr(IMulExpr* expr);
    void visitIDivExpr(IDivExpr* expr);

    /* unary expressions*/
    void visitUnaryExpr(UnaryExpr* expr);
    void visitIntExpr(IntExpr* expr);
};