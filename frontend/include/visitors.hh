#pragma once
#include "decl_types.hh"
#include <string>


namespace Essembly {

class Expr;
class BinaryExpr;
class AddExpr;
class SubExpr;
class DivExpr;
class MulExpr;
class IDivExpr;
class IMulExpr;
class ISubExpr;
class IAddExpr;
class DDivExpr;
class DMulExpr;
class DSubExpr;
class DAddExpr;
class FDivExpr;
class FMulExpr;
class FSubExpr;
class FAddExpr;
class SDivExpr;
class SMulExpr;
class SSubExpr;
class SAddExpr;

class Stmt;
class BlockStmt;
class Declaration;
class ValueDeclaration;
class IntDeclaration;
class FloatDeclaration;
class DoubleDeclaration;
class StringDeclaration;
class BoolDeclaration;
class ShortDeclaration;

class PrimaryExpr;
class IntExpr;
class DoubleExpr;
class FloatExpr;
class ShortExpr;
class StringExpr;
class IdExpr;
class BoolExpr;

class UnaryExpr;
class UnaryNotExpr;
class UnaryMinusExpr;

class Visitor /* abstract visitor class */ {
public:
    virtual ~Visitor() = 0;
};

class PrintVisitor: public Visitor {
    /* overloading the visit method */
public:
    PrintVisitor();
    ~PrintVisitor() override;
private:
    void declarationHelper(Declaration*, const std::string& op);
    void binaryExprHelper(BinaryExpr*, const std::string& op);
    void unaryExprHelper(UnaryExpr*, const std::string& op);
public:
    void visitBlockStmt(BlockStmt*);

    void visitDeclaration(Declaration*);
    void visitBoolDeclaration(BoolDeclaration*);
    void visitShortDeclaration(ShortDeclaration*);
    void visitIntDeclaration(IntDeclaration*);
    void visitFloatDeclaration(FloatDeclaration*);
    void visitDoubleDeclaration(DoubleDeclaration*);
    void visitStringDeclaration(StringDeclaration*);

    void visitBinaryExpr(BinaryExpr* expr);
    void visitAddExpr(AddExpr* expr);
    void visitSubExpr(SubExpr* expr);
    void visitMulExpr(MulExpr* expr);
    void visitDivExpr(DivExpr* expr);

    void visitIAddExpr(IAddExpr* expr);
    void visitISubExpr(ISubExpr* expr);
    void visitIMulExpr(IMulExpr* expr);
    void visitIDivExpr(IDivExpr* expr);
    void visitFAddExpr(FAddExpr* expr);
    void visitFSubExpr(FSubExpr* expr);
    void visitFMulExpr(FMulExpr* expr);
    void visitFDivExpr(FDivExpr* expr);
    void visitDAddExpr(DAddExpr* expr);
    void visitDSubExpr(DSubExpr* expr);
    void visitDMulExpr(DMulExpr* expr);
    void visitDDivExpr(DDivExpr* expr);
    void visitSAddExpr(SAddExpr* expr);
    void visitSSubExpr(SSubExpr* expr);
    void visitSMulExpr(SMulExpr* expr);
    void visitSDivExpr(SDivExpr* expr);

    void visitUnaryExpr(UnaryExpr* expr);
    void visitUnaryNotExpr(UnaryNotExpr* expr);
    void visitUnaryMinusExpr(UnaryMinusExpr* expr);

    void visitPrimaryExpr(PrimaryExpr*);
    void visitBoolExpr(BoolExpr*);
    void visitShortExpr(ShortExpr*);
    void visitIntExpr(IntExpr*);
    void visitFloatExpr(FloatExpr*);
    void visitDoubleExpr(DoubleExpr*);
    void visitStringExpr(StringExpr*);
    void visitIdExpr(IdExpr*);
};

class TypeVisitor: public Visitor {
    /* overloading the visit method */
private:
    /* use this value to store the last declaration type */
    DECL declType;
public:
    TypeVisitor();
    ~TypeVisitor() override;
private:
    [[nodiscard]] DECL getDeclType(Expr*) noexcept;
    void binaryExprHelper(DECL, BinaryExpr*);
    void unaryExprHelper(DECL, UnaryExpr*);
public:
    void visitBlockStmt(BlockStmt*);

    void visitDeclaration(Declaration*);
    void visitBoolDeclaration(BoolDeclaration*);
    void visitShortDeclaration(ShortDeclaration*);
    void visitIntDeclaration(IntDeclaration*);
    void visitFloatDeclaration(FloatDeclaration*);
    void visitDoubleDeclaration(DoubleDeclaration*);
    void visitStringDeclaration(StringDeclaration*);

    void visitBinaryExpr(BinaryExpr* expr);
    void visitAddExpr(AddExpr* expr);
    void visitSubExpr(SubExpr* expr);
    void visitMulExpr(MulExpr* expr);
    void visitDivExpr(DivExpr* expr);

    void visitIAddExpr(IAddExpr* expr);
    void visitISubExpr(ISubExpr* expr);
    void visitIMulExpr(IMulExpr* expr);
    void visitIDivExpr(IDivExpr* expr);
    void visitFAddExpr(FAddExpr* expr);
    void visitFSubExpr(FSubExpr* expr);
    void visitFMulExpr(FMulExpr* expr);
    void visitFDivExpr(FDivExpr* expr);
    void visitDAddExpr(DAddExpr* expr);
    void visitDSubExpr(DSubExpr* expr);
    void visitDMulExpr(DMulExpr* expr);
    void visitDDivExpr(DDivExpr* expr);
    void visitSAddExpr(SAddExpr* expr);
    void visitSSubExpr(SSubExpr* expr);
    void visitSMulExpr(SMulExpr* expr);
    void visitSDivExpr(SDivExpr* expr);

    void visitUnaryExpr(UnaryExpr* expr);
    void visitUnaryNotExpr(UnaryNotExpr* expr);
    void visitUnaryMinusExpr(UnaryMinusExpr* expr);

    void visitPrimaryExpr(PrimaryExpr*);
    void visitBoolExpr(BoolExpr*);
    void visitShortExpr(ShortExpr*);
    void visitIntExpr(IntExpr*);
    void visitFloatExpr(FloatExpr*);
    void visitDoubleExpr(DoubleExpr*);
    void visitStringExpr(StringExpr*);
    void visitIdExpr(IdExpr*);
};


} // Essembly