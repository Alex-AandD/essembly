#include "frontend/include/FactoryDeclaration.hh"
#include "frontend/include/declarations.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/token.hh"
#include <memory>

namespace Essembly {

using u_ptrExpr = std::unique_ptr<Expr>;
using u_ptrDecl = std::unique_ptr<Declaration>;
using u_ptrToken = std::unique_ptr<Token>;
using u_ptrStmt = std::unique_ptr<Stmt>;

FactoryDeclaration::FactoryDeclaration() { }
FactoryDeclaration::~FactoryDeclaration() { }
/* STMTS*/

/* block statement */
[[nodiscard]] u_ptrStmt FactoryDeclaration::makeBlockStmt(u_ptrToken& lbrace, 
    std::vector<u_ptrStmt>& stmts, u_ptrToken& rbrace) {
    return std::make_unique<BlockStmt>(lbrace, stmts, rbrace);
}

/* DECLARATIONS */
[[nodiscard]] u_ptrStmt FactoryDeclaration::makeDeclaration(DECL type, u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr) {
    switch(type) {
        case DECL::INT: return makeIntDeclaration(declToken, idExpr, valueExpr);
        case DECL::SHORT: return makeShortDeclaration(declToken, idExpr, valueExpr);
        case DECL::FLOAT: return makeFloatDeclaration(declToken, idExpr, valueExpr);
        case DECL::DOUBLE: return makeDoubleDeclaration(declToken, idExpr, valueExpr);
        case DECL::STRING: return makeStringDeclaration(declToken, idExpr, valueExpr);
        case DECL::BOOL: return makeBoolDeclaration(declToken, idExpr, valueExpr);
        default: assert("implement declaration");
    }
    return nullptr;
}

[[nodiscard]] u_ptrStmt FactoryDeclaration::makeIntDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr) {
    return std::make_unique<IntDeclaration>(declToken, idExpr, valueExpr);
}

[[nodiscard]] u_ptrStmt FactoryDeclaration::makeShortDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr) {
    return std::make_unique<ShortDeclaration>(declToken, idExpr, valueExpr);
}

[[nodiscard]] u_ptrStmt FactoryDeclaration::makeDoubleDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr) {
    return std::make_unique<DoubleDeclaration>(declToken, idExpr, valueExpr);
}

[[nodiscard]] u_ptrStmt FactoryDeclaration::makeBoolDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr) {
    return std::make_unique<DoubleDeclaration>(declToken, idExpr, valueExpr);
}

[[nodiscard]] u_ptrStmt FactoryDeclaration::makeFloatDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr) {
    return std::make_unique<FloatDeclaration>(declToken, idExpr, valueExpr);
}

[[nodiscard]] u_ptrStmt FactoryDeclaration::makeStringDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr) {
    return std::make_unique<StringDeclaration>(declToken, idExpr, valueExpr);
}

[[nodiscard]] u_ptrStmt FactoryDeclaration::makeDynamicDeclaration(u_ptrExpr& idExpr, u_ptrExpr& valueExpr) {
    return std::make_unique<DynamicDeclaration>(idExpr, valueExpr);
}


/* EXPRESSIONS */
[[nodiscard]] u_ptrExpr FactoryDeclaration::makeAdd(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case DECL::INT: return std::move(std::make_unique<IAddExpr>(_op, l, r));
        case DECL::SHORT: return std::move(std::make_unique<SAddExpr>(_op, l, r));
        case DECL::FLOAT: return std::move(std::make_unique<FAddExpr>(_op, l, r));
        case DECL::DOUBLE: return std::move(std::make_unique<DAddExpr>(_op, l, r));
        default: return std::move(std::make_unique<DynamicAddExpr>(_op, l, r));
    }
    return nullptr;
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeSub(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case DECL::INT: return std::make_unique<ISubExpr>(_op, l, r);
        case DECL::SHORT: return std::move(std::make_unique<SSubExpr>(_op, l, r));
        case DECL::FLOAT: return std::move(std::make_unique<FSubExpr>(_op, l, r));
        case DECL::DOUBLE: return std::move(std::make_unique<DSubExpr>(_op, l, r));
        default: return std::move(std::make_unique<DynamicSubExpr>(_op, l, r));
    }
    return nullptr;
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeMul(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case DECL::INT: return std::move(std::make_unique<IMulExpr>(_op, l, r));
        case DECL::SHORT: return std::move(std::make_unique<SMulExpr>(_op, l, r));
        case DECL::FLOAT: return std::move(std::make_unique<FMulExpr>(_op, l, r));
        case DECL::DOUBLE: return std::move(std::make_unique<DMulExpr>(_op, l, r));
        default: return std::move(std::make_unique<DynamicMulExpr>(_op, l, r));
    }
    return nullptr;
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeDiv(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) {
    switch(exprType) {
        case DECL::INT: return std::move(std::make_unique<IDivExpr>(_op, l, r));
        case DECL::SHORT: return std::move(std::make_unique<SDivExpr>(_op, l, r));
        case DECL::FLOAT: return std::move(std::make_unique<FDivExpr>(_op, l, r));
        case DECL::DOUBLE: return std::move(std::make_unique<DDivExpr>(_op, l, r));
        default: return std::move(std::make_unique<DynamicDivExpr>(_op, l, r));
    }
    return nullptr;
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeUnary(u_ptrToken& _op, u_ptrExpr& r) noexcept {
    switch(_op->type) {
        case TT::MINUS: return std::make_unique<UnaryMinusExpr>(_op, r);
        case TT::NOT: return std::make_unique<UnaryNotExpr>(_op, r);
        default: break;
    }
    return nullptr;
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeIntegerExpr(DECL declType, u_ptrToken& _op, const std::string& lex) noexcept {
    switch(declType) {
        case DECL::SHORT: return makeShortExpr(_op, lex);
        default: return makeIntExpr(_op, lex);
    } 
    return nullptr;
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeIntExpr(u_ptrToken& _op, const std::string& lex) noexcept {
    int value = std::stoi(lex);
    return std::make_unique<IntExpr>(_op, value);
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeDecimalExpr(DECL declType, u_ptrToken& _op, const std::string& lex) noexcept {
    switch(declType) {
        case DECL::FLOAT: return makeFloatExpr(_op, lex);
        default: return makeDoubleExpr(_op, lex);
    } 
    return nullptr;
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeFloatExpr(u_ptrToken& _op, const std::string& lex) noexcept {
    float value = std::stof(lex);
    return std::make_unique<FloatExpr>(_op, value);
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeDoubleExpr(u_ptrToken& _op, const std::string& lex) noexcept {
    double value = std::stod(lex);
    return std::make_unique<DoubleExpr>(_op, value);
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeBoolExpr(u_ptrToken& _op, bool value) noexcept {
    return std::make_unique<BoolExpr>(_op, value);
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeStringExpr(u_ptrToken& _op, const std::string& lex) noexcept {
    return std::make_unique<StringExpr>(_op, lex);
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeShortExpr(u_ptrToken& _op, const std::string& lex) noexcept {
    short value = std::stoi(lex);
    return std::make_unique<ShortExpr>(_op, value);
}

[[nodiscard]] u_ptrExpr FactoryDeclaration::makeIdExpr(DECL exprType, u_ptrToken& _op, const std::string& lex) noexcept {
    switch(exprType) {
        case DECL::INT: return std::move(std::make_unique<IIdExpr>(_op, lex));
        case DECL::SHORT: return std::move(std::make_unique<SIdExpr>(_op, lex));
        case DECL::FLOAT: return std::move(std::make_unique<FIdExpr>(_op, lex));
        case DECL::DOUBLE: return std::move(std::make_unique<DIdExpr>(_op, lex));
        case DECL::STRING: return std::move(std::make_unique<StringIdExpr>(_op, lex));
        case DECL::BOOL: return std::move(std::make_unique<BoolIdExpr>(_op, lex));
        default: return std::move(std::make_unique<DynamicIdExpr>(_op, lex));
    }
    return nullptr;
}
} // Essembly