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
class IEqExpr;
class FEqExpr;
class DEqExpr;
class SEqExpr;
class StringEqExpr;
class BoolEqExpr;
class DynamicEqExpr;

class INeqExpr;
class FNeqExpr;
class DNeqExpr;
class SNeqExpr;
class StringNeqExpr;
class BoolNeqExpr;

class DynamicAddExpr;
class DynamicSubExpr;
class DynamicMulExpr;
class DynamicDivExpr;

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
class BoolExpr;

class IdExpr;
class IIdExpr;
class SIdExpr;
class DIdExpr;
class FIdExpr;
class BoolIdExpr;
class StringIdExpr;
class DynamicIdExpr;

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
    
    void visitDynamicAddExpr(DynamicAddExpr* expr);
    void visitDynamicSubExpr(DynamicSubExpr* expr);
    void visitDynamicMulExpr(DynamicMulExpr* expr);
    void visitDynamicDivExpr(DynamicDivExpr* expr);

    void visitIEqExpr(IEqExpr* expr);
    void visitSEqExpr(SEqExpr* expr);
    void visitFEqExpr(FEqExpr* expr);
    void visitDEqExpr(DEqExpr* expr);
    void visitStringEqExpr(StringEqExpr* expr);
    void visitBoolEqExpr(BoolEqExpr* expr);
    void visitDynamicEqExpr(DynamicEqExpr* expr);
    void visitDynamicNeqExpr(DynamicNeqExpr* expr);

    void visitINeqExpr(INeqExpr* expr);
    void visitSNeqExpr(SNeqExpr* expr);
    void visitFNeqExpr(FNeqExpr* expr);
    void visitDNeqExpr(DNeqExpr* expr);
    void visitStringNeqExpr(StringNeqExpr* expr);
    void visitBoolNeqExpr(BoolNeqExpr* expr);

    void visitUnaryExpr(UnaryExpr* expr);
    void visitUnaryNotExpr(UnaryNotExpr* expr);
    void visitUnaryMinusExpr(UnaryMinusExpr* expr);

    void visitBoolExpr(BoolExpr*);
    void visitShortExpr(ShortExpr*);
    void visitIntExpr(IntExpr*);
    void visitFloatExpr(FloatExpr*);
    void visitDoubleExpr(DoubleExpr*);
    void visitStringExpr(StringExpr*);
    void visitIdExpr(IdExpr*);
    void visitIIdExpr(IIdExpr*);
    void visitSIdExpr(SIdExpr*);
    void visitDIdExpr(DIdExpr*);
    void visitFIdExpr(FIdExpr*);
    void visitStringIdExpr(StringIdExpr*);
    void visitBoolIdExpr(BoolIdExpr*);
    void visitDynamicIdExpr(DynamicIdExpr*);
};

class TypeVisitor: public Visitor {
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
    void binaryDynamicExprHelper(Expr*); 
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

    void visitDynamicAddExpr(DynamicAddExpr* expr);
    void visitDynamicSubExpr(DynamicSubExpr* expr);
    void visitDynamicMulExpr(DynamicMulExpr* expr);
    void visitDynamicDivExpr(DynamicDivExpr* expr);

    void visitIEqExpr(IEqExpr* expr);
    void visitSEqExpr(SEqExpr* expr);
    void visitFEqExpr(FEqExpr* expr);
    void visitDEqExpr(DEqExpr* expr);
    void visitStringEqExpr(StringEqExpr* expr);
    void visitBoolEqExpr(BoolEqExpr* expr);
    void visitDynamicEqExpr(DynamicEqExpr* expr);

    void visitINeqExpr(INeqExpr* expr);
    void visitSNeqExpr(SNeqExpr* expr);
    void visitFNeqExpr(FNeqExpr* expr);
    void visitDNeqExpr(DNeqExpr* expr);
    void visitStringNeqExpr(StringNeqExpr* expr);
    void visitBoolNeqExpr(BoolNeqExpr* expr);
    void visitDynamicNeqExpr(DynamicNeqExpr* expr);

    void visitUnaryExpr(UnaryExpr* expr);
    void visitUnaryNotExpr(UnaryNotExpr* expr);
    void visitUnaryMinusExpr(UnaryMinusExpr* expr);

    void visitIntExpr(IntExpr*);
    void visitShortExpr(ShortExpr*);
    void visitFloatExpr(FloatExpr*);
    void visitDoubleExpr(DoubleExpr*);
    void visitStringExpr(StringExpr*);
    void visitBoolExpr(BoolExpr*);
    void visitTrueExpr(TrueExpr*);
    void visitFalseExpr(FalseExpr*);

    void visitIdExpr(IdExpr*);
    void visitIIdExpr(IIdExpr*);
    void visitSIdExpr(SIdExpr*);
    void visitDIdExpr(DIdExpr*);
    void visitFIdExpr(FIdExpr*);
    void visitStringIdExpr(StringIdExpr*);
    void visitBoolIdExpr(BoolIdExpr*);
    void visitDynamicIdExpr(DynamicIdExpr*);
};


} // Essembly