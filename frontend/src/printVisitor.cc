#include "../include/printVisitor.hh"
#include "../include/token.hh"
#include <string>

PrintVisitor::PrintVisitor() { };
PrintVisitor::~PrintVisitor() { }

std::string PrintVisitor::binaryExprHelper(BinaryExpr* expr, std::string op) {
    std::string lhs = expr->lhs->acceptPrintVisitor(this);
    std::string rhs = expr->rhs->acceptPrintVisitor(this);
    return "(" + lhs + op + rhs + ")";
}

[[nodiscard]] std::string PrintVisitor::unaryExprHelper(UnaryExpr* expr, std::string op) {
    std::string rhs = expr->expr->acceptPrintVisitor(this);
    return "(" + op + rhs + ")";
}

/* first all the binary expressions */
[[nodiscard]] std::string PrintVisitor::visitBinaryExpr(BinaryExpr* expr) {
    std::string op = TokentoString(expr->op);
    return binaryExprHelper(expr, op);
}

[[nodiscard]] std::string PrintVisitor::visitAddExpr(AddExpr* expr) {
    return visitBinaryExpr(expr);
}

[[nodiscard]] std::string PrintVisitor::visitSubExpr(SubExpr* expr) {
    return visitBinaryExpr(expr);
}

[[nodiscard]] std::string PrintVisitor::visitDivExpr(DivExpr* expr) {
    return visitBinaryExpr(expr);
}

[[nodiscard]] std::string PrintVisitor::visitMulExpr(MulExpr* expr) {
    return visitBinaryExpr(expr);
}

std::string PrintVisitor::visitIAddExpr(IAddExpr* expr) {
    return binaryExprHelper(expr, "+");
}

std::string PrintVisitor::visitISubExpr(ISubExpr* expr) {
    return binaryExprHelper(expr, "-");
}

std::string PrintVisitor::visitIMulExpr(IMulExpr* expr) {
    return binaryExprHelper(expr, "*");
}

std::string PrintVisitor::visitIDivExpr(IDivExpr* expr) {
    return binaryExprHelper(expr, "/");
}

std::string PrintVisitor::visitUnaryExpr(UnaryExpr* expr) { 
    std::string op = TokentoString(expr->op);
    return unaryExprHelper(expr, op);
}

std::string PrintVisitor::visitUnaryNotExpr(UnaryNotExpr* expr) { 
    return unaryExprHelper(expr, "-");
}

std::string PrintVisitor::visitUnaryMinusExpr(UnaryMinusExpr* expr) { 
    return unaryExprHelper(expr, "-");
}


std::string PrintVisitor::visitIntExpr(IntExpr* expr) {
    return std::to_string(expr->value);
}