#pragma once

#include "expr.hh"
#include <string>

class PrintVisitor {
public:
    PrintVisitor();
    ~PrintVisitor();
private: /* these are some helpers to avoid repeating code */
    std::string binaryExprHelper(BinaryExpr* expr, std::string op);
    std::string unaryExprHelper(UnaryExpr* expr, std::string op);

public:
    /* all the binary operations */
    std::string visitBinaryExpr(BinaryExpr* expr);
    std::string visitIAddExpr(IAddExpr* expr);
    std::string visitISubExpr(ISubExpr* expr);
    std::string visitIMulExpr(IMulExpr* expr);
    std::string visitIDivExpr(IDivExpr* expr);

    std::string visitUnaryExpr(UnaryExpr* expr);
    std::string visitUnaryNotExpr(UnaryNotExpr* expr);
    std::string visitUnaryMinusExpr(UnaryMinusExpr* expr);
    std::string visitIntExpr(IntExpr* expr);
};