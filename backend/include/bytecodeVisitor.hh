#pragma once
#include <vector>

class BinaryExpr;
class IntExpr;
class UnaryExpr;
class Instruction;
class AddExpr;
class SubExpr;
class DivExpr;
class MulExpr;
class IAddExpr;
class ISubExpr;
class IDivExpr;
class IMulExpr;
class UnaryNotExpr;
class UnaryMinusExpr;


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
    void visitAddExpr(AddExpr* expr);
    void visitSubExpr(SubExpr* expr);
    void visitMulExpr(MulExpr* expr);
    void visitDivExpr(DivExpr* expr);
    void visitIAddExpr(IAddExpr* expr);
    void visitISubExpr(ISubExpr* expr);
    void visitIMulExpr(IMulExpr* expr);
    void visitIDivExpr(IDivExpr* expr);

    /* unary expressions*/
    void visitUnaryExpr(UnaryExpr* expr);
    void visitUnaryNotExpr(UnaryNotExpr* expr);
    void visitUnaryMinusExpr(UnaryMinusExpr* expr);

    /* primary expresssions */
    void visitIntExpr(IntExpr* expr);
}; 