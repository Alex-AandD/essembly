#include "frontend/include/visitors.hh"
#include "frontend/include/declarations.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/token.hh"
#include <iostream>
#include <string>

#define PRINT_CHARACTERS(char) std::cout << char;

namespace Essembly {
Visitor::~Visitor() { }

PrintVisitor::PrintVisitor() { }
PrintVisitor::~PrintVisitor() { }

void PrintVisitor::visitBlockStmt(BlockStmt* block) {
    /* print all the statements contained inside the block */
    std::cout << "{ \n";
    for (const auto& stmt: block->stmts) {
        stmt->accept(*this);
    }
    std::cout << "\n}";
}

void PrintVisitor::visitDeclaration(Declaration* decl) {
    assert("do not use declaration for print visitor");
}

void PrintVisitor::declarationHelper(Declaration* decl, const std::string& typeString) {
    std::cout << typeString << " ";
    (decl->idExpr)->accept(*this);
    PRINT_CHARACTERS(" = ")
    (decl->valueExpr)->accept(*this);
}

void PrintVisitor::visitIntDeclaration(IntDeclaration* decl) {
    return declarationHelper(decl, "int");
}

void PrintVisitor::visitDoubleDeclaration(DoubleDeclaration* decl) {
    return declarationHelper(decl, "double");
}

void PrintVisitor::visitBoolDeclaration(BoolDeclaration* decl) {
    return declarationHelper(decl, "bool");
}

void PrintVisitor::visitFloatDeclaration(FloatDeclaration* decl) {
    return declarationHelper(decl, "float");
}

void PrintVisitor::visitStringDeclaration(StringDeclaration* decl) {
    return declarationHelper(decl, "string");
}

void PrintVisitor::visitShortDeclaration(ShortDeclaration* decl) {
    return declarationHelper(decl, "short");
}

/********************** 
********************** 
    EXPRESSIONS 
********************
**********************/
void PrintVisitor::binaryExprHelper(BinaryExpr* expr, const std::string& op) {
    PRINT_CHARACTERS("(");
    expr->lhs->accept(*this);
    std::cout << op << " "; 
    expr->rhs->accept(*this);
    PRINT_CHARACTERS(")");
}

void PrintVisitor::unaryExprHelper(UnaryExpr* expr, const std::string& op) {
    PRINT_CHARACTERS("(");
    std::cout << op << " ";
    expr->expr->accept(*this);
    PRINT_CHARACTERS(")");
}

/* first all the binary expressions */
void PrintVisitor::visitBinaryExpr(BinaryExpr* expr) {
    const std::string opString = TokentoString(expr->op.get());
    return binaryExprHelper(expr, opString);
}

void PrintVisitor::visitAddExpr(AddExpr* expr) {
    return visitBinaryExpr(expr);
}

void PrintVisitor::visitSubExpr(SubExpr* expr) {
    return visitBinaryExpr(expr);
}

void PrintVisitor::visitDivExpr(DivExpr* expr) {
    return visitBinaryExpr(expr);
}

void PrintVisitor::visitMulExpr(MulExpr* expr) {
    return visitBinaryExpr(expr);
}

void PrintVisitor::visitIAddExpr(IAddExpr* expr) {
    return binaryExprHelper(expr, "+");
}

void PrintVisitor::visitSAddExpr(SAddExpr* expr) {
    return binaryExprHelper(expr, "+");
}

void PrintVisitor::visitFAddExpr(FAddExpr* expr) {
    return binaryExprHelper(expr, "+");
}

void PrintVisitor::visitDAddExpr(DAddExpr* expr) {
    return binaryExprHelper(expr, "+");
}

void PrintVisitor::visitISubExpr(ISubExpr* expr) {
    return binaryExprHelper(expr, "-");
}

void PrintVisitor::visitFSubExpr(FSubExpr* expr) {
    return binaryExprHelper(expr, "-");
}

void PrintVisitor::visitDSubExpr(DSubExpr* expr) {
    return binaryExprHelper(expr, "-");
}

void PrintVisitor::visitSSubExpr(SSubExpr* expr) {
    return binaryExprHelper(expr, "-");
}

void PrintVisitor::visitIMulExpr(IMulExpr* expr) {
    return binaryExprHelper(expr, "*");
}

void PrintVisitor::visitFMulExpr(FMulExpr* expr) {
    return binaryExprHelper(expr, "*");
}

void PrintVisitor::visitDMulExpr(DMulExpr* expr) {
    return binaryExprHelper(expr, "*");
}

void PrintVisitor::visitSMulExpr(SMulExpr* expr) {
    return binaryExprHelper(expr, "*");
}

void PrintVisitor::visitIDivExpr(IDivExpr* expr) {
    return binaryExprHelper(expr, "/");
}

void PrintVisitor::visitFDivExpr(FDivExpr* expr) {
    return binaryExprHelper(expr, "/");
}

void PrintVisitor::visitDDivExpr(DDivExpr* expr) {
    return binaryExprHelper(expr, "/");
}

void PrintVisitor::visitSDivExpr(SDivExpr* expr) {
    return binaryExprHelper(expr, "/");
}

void PrintVisitor::visitUnaryExpr(UnaryExpr* expr) { 
    const std::string opString = TokentoString(expr->op.get());
    return unaryExprHelper(expr, opString);
}

void PrintVisitor::visitUnaryNotExpr(UnaryNotExpr* expr) { 
    return unaryExprHelper(expr, "-");
}

void PrintVisitor::visitUnaryMinusExpr(UnaryMinusExpr* expr) { 
    return unaryExprHelper(expr, "-");
}
/************************************/
/*  PRIMARY EXPRESSIONS */
/************************************/
void PrintVisitor::visitPrimaryExpr(PrimaryExpr* expr) {
    assert("do not use");
}

void PrintVisitor::visitIntExpr(IntExpr* expr) {
    std::cout << expr -> value; 
}
void PrintVisitor::visitShortExpr(ShortExpr* expr) {
    std::cout << expr -> value; 
}
void PrintVisitor::visitFloatExpr(FloatExpr* expr) {
    std::cout << expr -> value; 
}
void PrintVisitor::visitDoubleExpr(DoubleExpr* expr) {
    std::cout << expr -> value; 
}
void PrintVisitor::visitStringExpr(StringExpr* expr) {
    std::cout << expr -> value; 
}
void PrintVisitor::visitIdExpr(IdExpr* expr) {
    std::cout << expr -> name; 
}
void PrintVisitor::visitBoolExpr(BoolExpr* expr) {
    std::cout << expr -> value; 
}


} // Essembly
