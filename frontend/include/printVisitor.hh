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
    [[nodiscard]] std::string binaryExprHelper(BinaryExpr*, std::string op);
    [[nodiscard]] std::string unaryExprHelper(UnaryExpr*, std::string op);
public:
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