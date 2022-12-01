#include "frontend/include/FactoryExpr.hh"
#include "frontend/include/expr.hh"

FactoryExpr::FactoryExpr() {}
FactoryExpr::~FactoryExpr() { }

[[nodiscard]] AddExpr* FactoryExpr::makeAdd(TEXPR exprType, Token _op, Expr* l, Expr* r) {
    switch(exprType) {
        case TEXPR::INT: return new IAddExpr(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] SubExpr* FactoryExpr::makeSub(TEXPR exprType, Token _op, Expr* l, Expr* r) {
    switch(exprType) {
        case TEXPR::INT: return new ISubExpr(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] MulExpr* FactoryExpr::makeMul(TEXPR exprType, Token _op, Expr* l, Expr* r) {
    switch(exprType) {
        case TEXPR::INT: return new IMulExpr(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] DivExpr* FactoryExpr::makeDiv(TEXPR exprType, Token _op, Expr* l, Expr* r) {
    switch(exprType) {
        case TEXPR::INT: return new IDivExpr(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] UnaryExpr* FactoryExpr::makeUnary(Token _op, Expr* r) {
    switch(_op.type) {
        case TT::MINUS: return new UnaryMinusExpr(_op, r);
        case TT::NOT: return new UnaryNotExpr(_op, r);
        default: break;
    }
}

[[nodiscard]] IntExpr* FactoryExpr::makeInt(std::string lex) {
    int value = std::stoi(lex);
    return new IntExpr(value);
}