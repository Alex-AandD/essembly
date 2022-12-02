#include "frontend/include/parser.hh"
#include "frontend/include/token.hh"
#include "frontend/include/FactoryExpr.hh"

Parser::Parser(): factory(new FactoryExpr()), current(0) { }
Parser::Parser(std::vector<Token>, std::vector<std::string> lexemes): 
    tokens(tokens), lexemes(lexemes), current(0), factory(new FactoryExpr()) { }
Parser::~Parser() {
    if (AST) {
        delete AST;
        AST = nullptr;
    }

    if (factory) {
        delete factory;
    }
}

[[nodiscard]] Expr* Parser::makeBinaryExpr(TEXPR exprType, Token _op, Expr* l, Expr* r) noexcept {
    switch(_op.type) {
        case TT::PLUS:  return factory->makeAdd(exprType, _op, l, r);
        case TT::MINUS: return factory->makeSub(exprType, _op, l, r);
        case TT::TIMES: return factory->makeMul(exprType, _op, l, r);
        case TT::SLASH: return factory->makeDiv(exprType, _op, l, r);
        default: break;
    }
}

[[nodiscard]] Expr* Parser::makeUnaryExpr(Token _op, Expr* r) noexcept {
    return factory->makeUnary(_op, r);
}

[[nodiscard]] Expr* Parser::parse() {
    AST = expr(TEXPR::INT);
    return AST;
}

[[nodiscard]] Expr* Parser::expr(TEXPR exprType) {
    return term(exprType);
}

[[nodiscard]] Expr* Parser::term(TEXPR exprType) {
    Expr* lhs = factor(exprType);
    while (matchCurrent(TT::PLUS, TT::MINUS)) {
        Token op = previousToken();
        Expr* rhs = factor(exprType);
        lhs = makeBinaryExpr(exprType, op, lhs, rhs);
    }
    return lhs;
}
[[nodiscard]] Expr* Parser::factor(TEXPR exprType) {
    Expr* lhs = unary();
    while (matchCurrent(TT::TIMES, TT::SLASH)) {
        Token op = previousToken();
        Expr* rhs = unary();
        lhs = makeBinaryExpr(exprType, op, lhs, rhs);
    }
    return lhs;
}

[[nodiscard]] Expr* Parser::unary() {
    while(matchCurrent(TT::NOT, TT::MINUS)) {
        Token op = previousToken();
        Expr* rhs = unary();
        return makeUnaryExpr(op, rhs);
    }
    return primary();
}

[[nodiscard]] Expr* Parser::makeIntExpr() noexcept {
    return factory->makeInt(currentLexeme());
}

[[nodiscard]] Expr* Parser::primary() {
    if (matchCurrent(TT::INT_LITERAL)) return makeIntExpr();
    throw "unknown expression type";
}
