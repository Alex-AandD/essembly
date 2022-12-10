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

TypeVisitor::TypeVisitor() { }
TypeVisitor::~TypeVisitor() { }

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

/**********************************************
* TYPEVISITOR
/**********************************************/

[[nodiscard]] DECL TypeVisitor::getDeclType(Expr* expr) noexcept {
    expr->accept(*this);
    return declType;
}

void TypeVisitor::visitBlockStmt(BlockStmt* block) {
    for (auto& stmt: block->stmts) {
        stmt->accept(*this);
    }
}

[[nodiscard]] static bool compatible_with_bool(DECL type) noexcept {
    return type == DECL::BOOL;
}

[[nodiscard]] static bool compatible_with_string(DECL type) noexcept {
    return type == DECL::STRING;
}

[[nodiscard]] static bool compatible_with_short(DECL type) noexcept {
    return type == DECL::SHORT;
}

[[nodiscard]] static bool compatible_with_int(DECL type) noexcept {
    return type == DECL::INT || type == DECL::SHORT;
}

[[nodiscard]] static bool compatible_with_float(DECL type) noexcept {
    return type == DECL::FLOAT || type == DECL::INT || type == DECL::SHORT;
}

[[nodiscard]] static bool compatible_with_double(DECL type) noexcept {
    return type == DECL::DOUBLE || type == DECL::FLOAT || type == DECL::INT || type == DECL::SHORT;
}

void TypeVisitor::visitStringDeclaration(StringDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!compatible_with_string(type)) {
        assert("not compatible");
    }
}

void TypeVisitor::visitIntDeclaration(IntDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!compatible_with_int(type)) {
        assert("not compatible");
    }
}

void TypeVisitor::visitDoubleDeclaration(DoubleDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!compatible_with_double(type)) {
        assert("not compatible");
    }
}

void TypeVisitor::visitFloatDeclaration(FloatDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!compatible_with_float(type)) {
        assert("not compatible");
    }
}
void TypeVisitor::visitShortDeclaration(ShortDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!compatible_with_short(type)) {
        assert("not compatible");
    }
}
void TypeVisitor::visitBoolDeclaration(BoolDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!compatible_with_bool(type)) {
        assert("not compatible");
    }
}

/***********************************************/
/***********************************************/

[[nodiscard]] static bool are_compatible(DECL lhs, DECL rhs) {
    switch(lhs) {
        case DECL::INT: return compatible_with_int(rhs);
        case DECL::SHORT: return compatible_with_short(rhs);
        case DECL::DOUBLE: return compatible_with_double(rhs);
        case DECL::FLOAT: return compatible_with_float(rhs);
        default: assert("missing declaration type for compatibility");
    }
    return false;
}

[[nodiscard]] static bool types_are_compatible(DECL expectedType, DECL actualType) noexcept {
    switch(expectedType) {
        case DECL::INT: return compatible_with_int(actualType);
        case DECL::FLOAT: return compatible_with_float(actualType);
        case DECL::STRING: return compatible_with_string(actualType);
        case DECL::DOUBLE: return compatible_with_double(actualType);
        case DECL::SHORT: return compatible_with_short(actualType);
        default: assert("types not supported");
    }
    return false;
}

void TypeVisitor::binaryExprHelper(DECL expectedType, BinaryExpr* expr) {
    // call recursively the visit method
    DECL rhsType = getDeclType(expr->rhs.get());
    DECL lhsType = getDeclType(expr->lhs.get());
    
    // TODO: #15 find a clever way to visit the types @Alex-AandD
    // for now just a switch statement. Something better at a later point
    if (!types_are_compatible(expectedType, rhsType)) {
        assert("type error not implemented yet for rhs");
    }

    if (!types_are_compatible(expectedType, lhsType)) {
        assert("type error not implemented yet for lhs");
    }
}

DECL getBiggestType(DECL first, DECL second) {
    if (first > second) return first;
    return second;
}

void TypeVisitor::visitBinaryExpr(BinaryExpr* expr) {
    assert("visit for binary expression delete");
}

/* dynamic binary expressions */
void TypeVisitor::visitAddExpr(AddExpr* expr) {
    assert("visit for binary expression delete");
}

void TypeVisitor::visitSubExpr(SubExpr* expr) {
    assert("visit for binary expression delete");
}

void TypeVisitor::visitMulExpr(MulExpr* expr) {
    assert("visit for binary expression delete");
}

void TypeVisitor::visitDivExpr(DivExpr* expr) {
    assert("visit for binary expression delete");
}

/* integer expressions */
void TypeVisitor::visitIAddExpr(IAddExpr* expr) {
    return binaryExprHelper(DECL::INT, expr);
}


void TypeVisitor::visitISubExpr(ISubExpr* expr) {
    return binaryExprHelper(DECL::INT, expr);
}

void TypeVisitor::visitIMulExpr(IMulExpr* expr) {
    return binaryExprHelper(DECL::INT, expr);
}

void TypeVisitor::visitIDivExpr(IDivExpr* expr) {
    return binaryExprHelper(DECL::INT, expr);
}

/* short expressions */
void TypeVisitor::visitSAddExpr(SAddExpr* expr) {
    return binaryExprHelper(DECL::SHORT, expr);
}

void TypeVisitor::visitSSubExpr(SSubExpr* expr) {
    return binaryExprHelper(DECL::SHORT, expr);
}

void TypeVisitor::visitSMulExpr(SMulExpr* expr) {
    return binaryExprHelper(DECL::SHORT, expr);
}

void TypeVisitor::visitSDivExpr(SDivExpr* expr) {
    return binaryExprHelper(DECL::SHORT, expr);
}

/* double expressions */
void TypeVisitor::visitDAddExpr(DAddExpr* expr) {
    return binaryExprHelper(DECL::DOUBLE, expr);
}

void TypeVisitor::visitDSubExpr(DSubExpr* expr) {
    return binaryExprHelper(DECL::DOUBLE, expr);
}

void TypeVisitor::visitDMulExpr(DMulExpr* expr) {
    return binaryExprHelper(DECL::DOUBLE, expr);
}

void TypeVisitor::visitDDivExpr(DDivExpr* expr) {
    return binaryExprHelper(DECL::DOUBLE, expr);
}

/* float expressions */
void TypeVisitor::visitFAddExpr(FAddExpr* expr) {
    return binaryExprHelper(DECL::FLOAT, expr);
}

void TypeVisitor::visitFSubExpr(FSubExpr* expr) {
    return binaryExprHelper(DECL::FLOAT, expr);
}

void TypeVisitor::visitFMulExpr(FMulExpr* expr) {
    return binaryExprHelper(DECL::FLOAT, expr);
}

void TypeVisitor::visitFDivExpr(FDivExpr* expr) {
    return binaryExprHelper(DECL::FLOAT, expr);
}

/***********************************
 * EQUALITY
 * ********************************/
void TypeVisitor::visitIEqExpr(IEqExpr* expr) {

}

void TypeVisitor::visitSEqExpr(IEqExpr* expr) {

}

void TypeVisitor::visitDEqExpr(IEqExpr* expr) {

}

void TypeVisitor::visitFEqExpr(IEqExpr* expr) {

}

void TypeVisitor::visitBoolEqExpr(IEqExpr* expr) {

}

void TypeVisitor::visitStringEqExpr(IEqExpr* expr) {

}

void TypeVisitor::visitINeqExpr(INeqExpr* expr) {

}

void TypeVisitor::visitSNeqExpr(SNeqExpr* expr) {

}

void TypeVisitor::visitDNeqExpr(DNeqExpr* expr) {

}

void TypeVisitor::visitFNeqExpr(FNeqExpr* expr) {

}

void TypeVisitor::visitBoolNeqExpr(BoolNeqExpr* expr) {

}

void TypeVisitor::visitStringNeqExpr(StringNeqExpr* expr) {

}
/************************************/
/************************************/
void TypeVisitor::visitPrimaryExpr(PrimaryExpr* expr) {
    assert("primary expression method deleted");
}
void TypeVisitor::visitIntExpr(IntExpr* expr) {
    declType = DECL::INT;
}

void TypeVisitor::visitStringExpr(StringExpr* expr) {
    declType = DECL::STRING;
}

void TypeVisitor::visitFloatExpr(FloatExpr* expr) {
    declType = DECL::FLOAT;
}

void TypeVisitor::visitDoubleExpr(DoubleExpr* expr) {
    declType = DECL::DOUBLE; 
}


void TypeVisitor::visitShortExpr(ShortExpr* expr) {
    declType = DECL::SHORT;
}

void TypeVisitor::visitBoolExpr(BoolExpr* expr) {
    declType = DECL::BOOL;
}

void TypeVisitor::visitIdExpr(IdExpr* expr) {
    declType = expr->type;
}

void TypeVisitor::visitUnaryExpr(UnaryExpr* expr) {
    assert("not implemented");
}

void TypeVisitor::visitUnaryNotExpr(UnaryNotExpr* expr) {
    assert("not implemented");
}

void TypeVisitor::visitUnaryMinusExpr(UnaryMinusExpr* expr) {
    assert("not implemented");
}

} // Essembly
