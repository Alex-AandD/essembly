#include "frontend/include/parser.hh"
#include "frontend/include/token.hh"
#include "frontend/include/FactoryDeclaration.hh"
#include "frontend/include/printVisitor.hh"
#include <iostream>

/* USE OF SMART AND RAW POINTERS */
/* FACTORIES CAN RETURN SMART POINTERS */
/* THE EXPRESSIONS THAT MAKE UP THE AST WILL BE SMART POINTERS */
/* VISITORS DO NOT OWN ANYTHING, THEREFORE THEY ONLY GET A RAW POINTER */

namespace Essembly {

Parser::Parser(): 
    factory(std::make_unique<FactoryDeclaration>()), 
    printVisitor(std::make_unique<PrintVisitor>()),
    AST(nullptr),
    t_current(0),
    l_current(0)
    { }


Parser::Parser(std::vector<u_ptrToken> toks, std::vector<std::string> lexemes): 
    tokens(std::move(toks)), 
    lexemes(lexemes), 
    factory(std::make_unique<FactoryDeclaration>()),
    printVisitor(std::make_unique<PrintVisitor>()),
    AST(nullptr),
    t_current(0), 
    l_current(0)
    { }

void Parser::printAST() const {
    if (AST) {
        std::cout << AST -> acceptPrintVisitor(printVisitor.get()) << '\n';
    }
}


[[nodiscard]] u_ptrExpr Parser::makeBinaryExpr(TEXPR exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) noexcept {
    switch(_op->type) {
        case TT::PLUS:  return factory->makeAdd(exprType, _op, l, r);
        case TT::MINUS: return factory->makeSub(exprType, _op, l, r);
        case TT::TIMES: return factory->makeMul(exprType, _op, l, r);
        case TT::SLASH: return factory->makeDiv(exprType, _op, l, r);
        default: break;
    }
}

[[nodiscard]] u_ptrExpr Parser::makeUnaryExpr(u_ptrToken& _op, u_ptrExpr& r) noexcept {
    return factory->makeUnary(_op, r);
}

[[nodiscard]] u_ptrExpr Parser::parse() {
    AST = declaration();
    return std::move(AST);
}

[[nodiscard]] u_ptrExpr Parser::expr(DECL exprType) {
    return term(exprType);
}
   
   

[[nodiscard]] u_ptrExpr Parser::term(DECL exprType) {
    u_ptrExpr lhs = factor(exprType);
    while (matchCurrent(TT::PLUS, TT::MINUS)) {
        u_ptrToken op = previousToken();
        u_ptrExpr rhs = factor(exprType);
        lhs = makeBinaryExpr(exprType, op, lhs, rhs);
    }
    return lhs;
}
[[nodiscard]] u_ptrExpr Parser::factor(DECL exprType) {
    u_ptrExpr lhs = unary();
    while (matchCurrent(TT::TIMES, TT::SLASH)) {
        u_ptrToken op = previousToken();
        u_ptrExpr rhs = unary();
        lhs = makeBinaryExpr(exprType, op, lhs, rhs);
    }
    return lhs;
}

[[nodiscard]] u_ptrExpr Parser::unary() {
    while(matchCurrent(TT::NOT, TT::MINUS)) {
        u_ptrToken op = previousToken();
        u_ptrExpr rhs = unary();
        return makeUnaryExpr(op, rhs);
    }
    return primary();
}

[[nodiscard]] u_ptrExpr Parser::makeIntExpr() noexcept {
    u_ptrExpr expr = factory->makeInt(currentLexeme());
    advanceLexeme();
    return expr;
}

[[nodiscard]] u_ptrExpr Parser::primary() {
    if (matchCurrent(TT::INT_LITERAL)) return makeIntExpr();
    if (matchCurrent(TT::ID)) return ;
    else { throw "unknown expression type"; }
}

} // Essembly