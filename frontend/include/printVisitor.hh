#pragma once

#include "expr.hh"
#include <string>

class PrintVisitor {
public:
    PrintVisitor();
    ~PrintVisitor();
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
    [[nodiscard]] std::string visitUnaryExpr(UnaryExpr* expr);
    [[nodiscard]] std::string visitUnaryNotExpr(UnaryNotExpr* expr);
    [[nodiscard]] std::string visitUnaryMinusExpr(UnaryMinusExpr* expr);
    [[nodiscard]] std::string visitIntExpr(IntExpr* expr);
};