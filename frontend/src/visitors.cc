#include "frontend/include/visitors.hh"
#include "frontend/include/declarations.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/token.hh"
#include "frontend/include/compatibility.hh"

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

/*********************************
 * == EXPRESSIONS
 ********************************/
void PrintVisitor::visitIEqExpr(IEqExpr* expr) {
    return binaryExprHelper(expr, "==");
}

void PrintVisitor::visitSEqExpr(SEqExpr* expr) {
    return binaryExprHelper(expr, "==");
}

void PrintVisitor::visitFEqExpr(FEqExpr* expr) {
    return binaryExprHelper(expr, "==");
}

void PrintVisitor::visitDEqExpr(DEqExpr* expr) {
    return binaryExprHelper(expr, "==");
}

void PrintVisitor::visitBoolEqExpr(BoolEqExpr* expr) {
    return binaryExprHelper(expr, "==");
}

void PrintVisitor::visitStringEqExpr(StringEqExpr* expr) {
    return binaryExprHelper(expr, "==");
}

/*********************************
 *             NEQ             
 ********************************/

void PrintVisitor::visitINeqExpr(INeqExpr* expr) {
    return binaryExprHelper(expr, "!=");
}

void PrintVisitor::visitSNeqExpr(SNeqExpr* expr) {
    return binaryExprHelper(expr, "!=");
}

void PrintVisitor::visitFNeqExpr(FNeqExpr* expr) {
    return binaryExprHelper(expr, "!=");
}

void PrintVisitor::visitDNeqExpr(DNeqExpr* expr) {
    return binaryExprHelper(expr, "!=");
}

void PrintVisitor::visitBoolNeqExpr(BoolNeqExpr* expr) {
    return binaryExprHelper(expr, "!=");
}

void PrintVisitor::visitStringNeqExpr(StringNeqExpr* expr) {
    return binaryExprHelper(expr, "!=");
}

/*********************************
 * UNARY EXPRESSIONS
 ********************************/

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

/************************************
 * PRIMARY EXPRESSIONS 
************************************/

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
void PrintVisitor::visitBoolExpr(BoolExpr* expr) {
    std::cout << expr -> value; 
}
void PrintVisitor::visitIdExpr(IdExpr* expr) {
    std::cout << expr -> name;
}
void PrintVisitor::visitIIdExpr(IIdExpr* expr) {
    std::cout << expr -> name << "(INT)"; 
}
void PrintVisitor::visitSIdExpr(SIdExpr* expr) {
    std::cout << expr -> name << "(SHORT)"; 
}
void PrintVisitor::visitFIdExpr(FIdExpr* expr) {
    std::cout << expr -> name << "(FLOAT)"; 
}
void PrintVisitor::visitDIdExpr(DIdExpr* expr) {
    std::cout << expr -> name << "(DOUBLE)"; 
}
void PrintVisitor::visitStringIdExpr(StringIdExpr* expr) {
    std::cout << expr -> name << "(STRING)"; 
}
void PrintVisitor::visitBoolIdExpr(BoolIdExpr* expr) {
    std::cout << expr -> name << "(BOOL)"; 
}

/*********************************
 * TYPEVISITOR
 * ******************************/

[[nodiscard]] DECL TypeVisitor::getDeclType(Expr* expr) noexcept {
    expr->accept(*this);
    return declType;
}

void TypeVisitor::visitBlockStmt(BlockStmt* block) {
    for (auto& stmt: block->stmts) {
        stmt->accept(*this);
    }
}


void TypeVisitor::visitStringDeclaration(StringDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!compatible_with_string(type)) {
        assert("not compatible");
    }
}

void TypeVisitor::visitIntDeclaration(IntDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!strictly_compatible_with_int(type)) {
        assert("not compatible");
    }
}

void TypeVisitor::visitDoubleDeclaration(DoubleDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!strictly_compatible_with_double(type)) {
        assert("not compatible");
    }
}

void TypeVisitor::visitFloatDeclaration(FloatDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!strictly_compatible_with_float(type)) {
        assert("not compatible");
    }
}
void TypeVisitor::visitShortDeclaration(ShortDeclaration* declaration) {
    DECL type = getDeclType((declaration->valueExpr).get());   
    if (!strictly_compatible_with_short(type)) {
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

DECL getBiggestType(DECL first, DECL second) {
    if (first > second) return first;
    return second;
}

[[nodiscard]] static bool types_are_strictly_compatible(DECL expectedType, DECL actualType) noexcept {
    switch(expectedType) {
        case DECL::INT: return strictly_compatible_with_int(actualType);
        case DECL::FLOAT: return strictly_compatible_with_float(actualType);
        case DECL::SHORT: return strictly_compatible_with_short(actualType);
        case DECL::DOUBLE: return strictly_compatible_with_double(actualType);
        case DECL::STRING: return compatible_with_string(actualType);
        case DECL::BOOL: return compatible_with_bool(actualType);
        default: assert("types not supported");
    }
    return false;
}

/*********************************************
 * BINARY EXPR HELPER
 * *******************************************/

void TypeVisitor::binaryExprHelper(DECL expectedType, BinaryExpr* expr) {
    // call recursively the visit method
    DECL rhsType = getDeclType(expr->rhs.get());
    DECL lhsType = getDeclType(expr->lhs.get());
    
    // TODO: #15 find a clever way to visit the types @Alex-AandD
    // for now just a switch statement. Something better at a later point
    if (!types_are_strictly_compatible(expectedType, rhsType)) {
        assert("type error not implemented yet for rhs");
    }

    if (!types_are_strictly_compatible(expectedType, lhsType)) {
        assert("type error not implemented yet for lhs");
    }
}

/***************************************
 * VISITORS
 * *************************************/

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

/************************************
 * INTEGER EXPRESSIONS
 * *********************************/

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
    return binaryExprHelper(DECL::INT, expr);
}

void TypeVisitor::visitSEqExpr(SEqExpr* expr) {
    return binaryExprHelper(DECL::SHORT, expr);
}

void TypeVisitor::visitDEqExpr(DEqExpr* expr) {
    return binaryExprHelper(DECL::DOUBLE, expr);
}

void TypeVisitor::visitFEqExpr(FEqExpr* expr) {
    return binaryExprHelper(DECL::FLOAT, expr);
}

void TypeVisitor::visitBoolEqExpr(BoolEqExpr* expr) {
    return binaryExprHelper(DECL::BOOL, expr);
}

void TypeVisitor::visitStringEqExpr(StringEqExpr* expr) {
    return binaryExprHelper(DECL::STRING, expr);
}

void TypeVisitor::visitINeqExpr(INeqExpr* expr) {
    return binaryExprHelper(DECL::INT, expr);
}

void TypeVisitor::visitSNeqExpr(SNeqExpr* expr) {
    return binaryExprHelper(DECL::SHORT, expr);
}

void TypeVisitor::visitDNeqExpr(DNeqExpr* expr) {
    return binaryExprHelper(DECL::DOUBLE, expr);
}

void TypeVisitor::visitFNeqExpr(FNeqExpr* expr) {
    return binaryExprHelper(DECL::FLOAT, expr);
}

void TypeVisitor::visitBoolNeqExpr(BoolNeqExpr* expr) {
    return binaryExprHelper(DECL::BOOL, expr);
}

void TypeVisitor::visitStringNeqExpr(StringNeqExpr* expr) {
    return binaryExprHelper(DECL::STRING, expr);
}

/************************************
 * DYNAMIC EXPRESSIONS
 * **********************************/
void TypeVisitor::binaryDynamicExprHelper(Expr* expr) {
    /* how do we solve dynamic expressions */ 
}

void TypeVisitor::visitDynamicSubExpr(DynamicSubExpr* expr) {
    return binaryDynamicExprHelper(expr);
}

void TypeVisitor::visitDynamicAddExpr(DynamicAddExpr* expr) {
    return binaryDynamicExprHelper(expr);
}

void TypeVisitor::visitDynamicMulExpr(DynamicMulExpr* expr) {
    return binaryDynamicExprHelper(expr);
}

void TypeVisitor::visitDynamicDivExpr(DynamicDivExpr* expr) {
    return binaryDynamicExprHelper(expr);
}

void TypeVisitor::visitDynamicEqExpr(DynamicEqExpr* expr) {
    return binaryDynamicExprHelper(expr);
}

void TypeVisitor::visitDynamicNeqExpr(DynamicNeqExpr* expr) {
    return binaryDynamicExprHelper(expr);
}

void TypeVisitor::visitDynamicIdExpr(DynamicIdExpr* expr) {
    return binaryDynamicExprHelper(expr);
}

/************************************
 * PRIMARY EXPRESSIONS
 * *********************************/

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
    // delete this method
}

void TypeVisitor::visitIIdExpr(IIdExpr* expr) {
    declType = DECL::INT;
}

void TypeVisitor::visitSIdExpr(SIdExpr* expr) {
    declType = DECL::SHORT;
}

void TypeVisitor::visitFIdExpr(FIdExpr* expr) {
    declType = DECL::FLOAT;
}

void TypeVisitor::visitDIdExpr(DIdExpr* expr) {
    declType = DECL::DOUBLE;
}

void TypeVisitor::visitStringIdExpr(StringIdExpr* expr) {
    declType = DECL::STRING;
}

void TypeVisitor::visitBoolIdExpr(BoolIdExpr* expr) {
    declType = DECL::BOOL;
}

/*********************************
 * UNARY EXPRESSIONS
 * ******************************/

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
