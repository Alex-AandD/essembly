#pragma once

#include <string>
#include <memory>

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


class UnaryExpr;
class PrimaryExpr;
class IntExpr;
class DoubleExpr;
class FloatExpr;
class StringExpr;
class IdExpr;
class BoolExpr;
class UnaryNotExpr;
class UnaryMinusExpr;

class PrintVisitor {
public:
    PrintVisitor();
private:
    [[nodiscard]] std::string declarationHelper(ValueDeclaration*, const std::string& op);
    [[nodiscard]] std::string binaryExprHelper(BinaryExpr*, const std::string& op);
    [[nodiscard]] std::string unaryExprHelper(UnaryExpr*, const std::string& op);
public:
    [[nodiscard]] std::string visitBlockStmt(BlockStmt*);
    [[nodiscard]] std::string visitValueDeclaration(ValueDeclaration*);
    [[nodiscard]] std::string visitIntDeclaration(IntDeclaration*);
    [[nodiscard]] std::string visitFloatDeclaration(FloatDeclaration*);
    [[nodiscard]] std::string visitStringDeclaration(StringDeclaration*);
    [[nodiscard]] std::string visitDoubleDeclaration(DoubleDeclaration*);
    [[nodiscard]] std::string visitBoolDeclaration(BoolDeclaration*);
    [[nodiscard]] std::string visitShortDeclaration(ShortDeclaration*);

    /* all the binary operations */
    [[nodiscard]] std::string visitBinaryExpr(BinaryExpr* expr);
    [[nodiscard]] std::string visitAddExpr(AddExpr* expr);
    [[nodiscard]] std::string visitSubExpr(SubExpr* expr);
    [[nodiscard]] std::string visitMulExpr(MulExpr* expr);
    [[nodiscard]] std::string visitDivExpr(DivExpr* expr);

    // TODO: #11 add const to printVisitor methods and check if something can throw @Alex-AandD
    [[nodiscard]] std::string visitIAddExpr(IAddExpr* expr);
    [[nodiscard]] std::string visitISubExpr(ISubExpr* expr);
    [[nodiscard]] std::string visitIMulExpr(IMulExpr* expr);
    [[nodiscard]] std::string visitIDivExpr(IDivExpr* expr);
    [[nodiscard]] std::string visitFAddExpr(FAddExpr* expr);
    [[nodiscard]] std::string visitFSubExpr(FSubExpr* expr);
    [[nodiscard]] std::string visitFMulExpr(FMulExpr* expr);
    [[nodiscard]] std::string visitFDivExpr(FDivExpr* expr);
    [[nodiscard]] std::string visitDAddExpr(DAddExpr* expr);
    [[nodiscard]] std::string visitDSubExpr(DSubExpr* expr);
    [[nodiscard]] std::string visitDMulExpr(DMulExpr* expr);
    [[nodiscard]] std::string visitDDivExpr(DDivExpr* expr);
    [[nodiscard]] std::string visitSAddExpr(SAddExpr* expr);
    [[nodiscard]] std::string visitSSubExpr(SSubExpr* expr);
    [[nodiscard]] std::string visitSMulExpr(SMulExpr* expr);
    [[nodiscard]] std::string visitSDivExpr(SDivExpr* expr);

    [[nodiscard]] std::string visitUnaryExpr(UnaryExpr* expr);
    [[nodiscard]] std::string visitUnaryNotExpr(UnaryNotExpr* expr);
    [[nodiscard]] std::string visitUnaryMinusExpr(UnaryMinusExpr* expr);

    [[nodiscard]] std::string visitIntExpr(IntExpr* expr);
    [[nodiscard]] std::string visitFloatExpr(FloatExpr* expr);
    [[nodiscard]] std::string visitDoubleExpr(DoubleExpr* expr);
    [[nodiscard]] std::string visitBoolExpr(BoolExpr* expr);
    [[nodiscard]] std::string visitStringExpr(StringExpr* expr);
    [[nodiscard]] std::string visitIdExpr(IdExpr* expr);
};
}