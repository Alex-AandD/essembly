#include "frontend/include/FactoryExpr.hh"
#include "frontend/include/expr.hh"

FactoryExpr::FactoryExpr() {}
FactoryExpr::~FactoryExpr() { }

[[nodiscard]] Expr* FactoryExpr::makeAdd(TEXPR exprType, Token _op, Expr* l, Expr* r) {
    switch(exprType) {
        case TEXPR::INT: return new IAddExpr(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] Expr* FactoryExpr::makeSub(TEXPR exprType, Token _op, Expr* l, Expr* r) {
    switch(exprType) {
        case TEXPR::INT: return new ISubExpr(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] Expr* FactoryExpr::makeMul(TEXPR exprType, Token _op, Expr* l, Expr* r) {
    switch(exprType) {
        case TEXPR::INT: return new IMulExpr(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] Expr* FactoryExpr::makeDiv(TEXPR exprType, Token _op, Expr* l, Expr* r) {
    switch(exprType) {
        case TEXPR::INT: return new IDivExpr(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] Expr* FactoryExpr::makeUnary(Token _op, Expr* r) noexcept {
    switch(_op.type) {
        case TT::MINUS: return new UnaryMinusExpr(_op, r);
        case TT::NOT: return new UnaryNotExpr(_op, r);
        default: break;
    }
}

[[nodiscard]] Expr* FactoryExpr::makeInt(std::string lex) noexcept {
    int value = std::stoi(lex);
    return new IntExpr(value);
}