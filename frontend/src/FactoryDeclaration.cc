#include "frontend/include/FactoryDeclaration.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/token.hh"

namespace Essembly {

using u_ptrExpr = std::unique_ptr<Expr>;
using u_ptrToken = std::unique_ptr<Token>;

FactoryDeclaration::FactoryDeclaration() { }
FactoryDeclaration::~FactoryDeclaration() { }

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeAdd(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case DECL::INT: return std::make_unique<IAddExpr>(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeSub(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case DECL::INT: return std::make_unique<ISubExpr>(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeMul(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case DECL::INT: return std::make_unique<IMulExpr>(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeDiv(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case DECL::INT: return std::make_unique<IDivExpr>(_op, l, r);
        default: throw "type for add expr not supported";
    }
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeUnary(u_ptrToken& _op, u_ptrExpr& r) noexcept {
    switch(_op->type) {
        case TT::MINUS: return std::make_unique<UnaryMinusExpr>(_op, r);
        case TT::NOT: return std::make_unique<UnaryNotExpr>(_op, r);
        default: break;
    }
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeInt(std::string lex) noexcept {
    int value = std::stoi(lex);
    return std::make_unique<IntExpr>(value);
}

} // Essembly