#pragma once
#include <vector>

class BinaryExpr;
class IntExpr;
class UnaryExpr;
class Instruction;
class IAddExpr;
class ISubExpr;
class IDivExpr;
class IMulExpr;


/* this visitor is going to generate raw and unoptimized bytecode */
class BytecodeVisitor {
    /* this is going to be the instruction vector placed inside of the generator */
    std::vector<Instruction*> instructions;
public:
    BytecodeVisitor(std::vector<Instruction*>& instr);
    ~BytecodeVisitor();
private:
    /* these are going to be some helpers to create bytecode */
    void binaryExprHelper(BinaryExpr* expr);
    void unaryExprHelper(UnaryExpr* expr);
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