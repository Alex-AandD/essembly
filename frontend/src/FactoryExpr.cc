#include "frontend/include/FactoryExpr.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/token.hh"

namespace Essembly {

using u_ptrExpr = std::unique_ptr<Expr>;
using u_ptrToken = std::unique_ptr<Token>;

FactoryExpr::FactoryExpr() { }
FactoryExpr::~FactoryExpr() { }

[[nodiscard]] u_ptrExpr FactoryExpr::makeAdd(TEXPR exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case TEXPR::INT: return std::make_unique<IAddExpr>(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] u_ptrExpr FactoryExpr::makeSub(TEXPR exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case TEXPR::INT: return std::make_unique<ISubExpr>(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] u_ptrExpr FactoryExpr::makeMul(TEXPR exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case TEXPR::INT: return std::make_unique<IMulExpr>(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] u_ptrExpr FactoryExpr::makeDiv(TEXPR exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case TEXPR::INT: return std::make_unique<IDivExpr>(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] u_ptrExpr FactoryExpr::makeUnary(u_ptrToken& _op, u_ptrExpr& r) noexcept {
    switch(_op->type) {
        case TT::MINUS: return std::make_unique<UnaryMinusExpr>(_op, r);
        case TT::NOT: return std::make_unique<UnaryNotExpr>(_op, r);
        default: break;
    }
}

[[nodiscard]] u_ptrExpr FactoryExpr::makeInt(std::string lex) noexcept {
    int value = std::stoi(lex);
    return std::make_unique<IntExpr>(value);
}

}