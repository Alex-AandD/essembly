#pragma once
#include <vector>


namespace Essembly {

class Instruction;

class BinaryExpr;
class IntExpr;
class UnaryExpr;

class AddExpr;
class SubExpr;
class DivExpr;
class MulExpr;

class IAddExpr;
class ISubExpr;
class IDivExpr;
class IMulExpr;

class SAddExpr;
class SSubExpr;
class SDivExpr;
class SMulExpr;

class FAddExpr;
class FSubExpr;
class FMulExpr;
class FDivExpr;

class DAddExpr;
class DSubExpr;
class DDivExpr;
class DMulExpr;

class UnaryNotExpr;
class UnaryMinusExpr;

/* this visitor is going to generate raw and unoptimized bytecode */
class BytecodeVisitor {
public:
    /* this is going to be the instruction vector placed inside of the generator */
    std::vector<Instruction*> instructions;
public:
    BytecodeVisitor();
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
    void visitSAddExpr(SAddExpr* expr);
    void visitSSubExpr(SSubExpr* expr);
    void visitSMulExpr(SMulExpr* expr);
    void visitSDivExpr(SDivExpr* expr);
    void visitFAddExpr(FAddExpr* expr);
    void visitFSubExpr(FSubExpr* expr);
    void visitFMulExpr(FMulExpr* expr);
    void visitFDivExpr(FDivExpr* expr);
    void visitDAddExpr(DAddExpr* expr);
    void visitDSubExpr(DSubExpr* expr);
    void visitDMulExpr(DMulExpr* expr);
    void visitDDivExpr(DDivExpr* expr);

    /* unary expressions*/
    void visitUnaryExpr(UnaryExpr* expr);
    void visitUnaryNotExpr(UnaryNotExpr* expr);
    void visitUnaryMinusExpr(UnaryMinusExpr* expr);

    /* primary expresssions */
    void visitIntExpr(IntExpr* expr);
    void visitDoubleExpr(DoubleExpr* expr);
    void visitFloatExpr(FloatExpr* expr);
    void visitShortExpr(FloatExpr* expr);
    void visitIdExpr(IdExpr* expr);
    void visitStringExpr(StringExpr* expr);
    void visitBoolExpr(BoolExpr* expr);
}; 
}