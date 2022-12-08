#pragma once
#include "decl_types.hh"
#include <memory>

namespace Essembly {

class Token;
class Expr;
class Stmt;
class AddExpr;
class MulExpr;
class SubExpr;
class DivExpr;
class UnaryExpr;
class IntExpr;
class FactoryDeclaration {

using u_ptrExpr = std::unique_ptr<Expr>;
using u_ptrStmt = std::unique_ptr<Stmt>;
using u_ptrToken = std::unique_ptr<Token>;

public:
    FactoryDeclaration();
    ~FactoryDeclaration();
public:

    [[nodiscard]] u_ptrStmt makeBlockStmt(u_ptrToken& lbrace, std::vector<u_ptrStmt>& stmts, u_ptrToken& rbrace);

    [[nodiscard]] u_ptrStmt makeDeclaration(DECL type, u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr);
    [[nodiscard]] u_ptrStmt makeIntDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr);
    [[nodiscard]] u_ptrStmt makeShortDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr);
    [[nodiscard]] u_ptrStmt makeFloatDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr);
    [[nodiscard]] u_ptrStmt makeDoubleDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr);
    [[nodiscard]] u_ptrStmt makeBoolDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr);
    [[nodiscard]] u_ptrStmt makeStringDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr);
    [[nodiscard]] u_ptrStmt makeDynamicDeclaration(u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr);

    /* expressions */
    [[nodiscard]] u_ptrExpr makeAdd(DECL, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r);
    [[nodiscard]] u_ptrExpr makeSub(DECL, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r);
    [[nodiscard]] u_ptrExpr makeMul(DECL, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r);
    [[nodiscard]] u_ptrExpr makeDiv(DECL, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r);

    [[nodiscard]] u_ptrExpr makeUnary(u_ptrToken& _op, u_ptrExpr& r) noexcept;
    [[nodiscard]] u_ptrExpr makePrimaryExpr(u_ptrToken& _op, const std::string& lex) noexcept;
    [[nodiscard]] u_ptrExpr makeIntExpr(u_ptrToken& _op, const std::string& lex) noexcept;
    [[nodiscard]] u_ptrExpr makeFloatExpr(u_ptrToken& _op, const std::string& lex) noexcept;
    [[nodiscard]] u_ptrExpr makeShortExpr(u_ptrToken& _op, const std::string& lex) noexcept;
    [[nodiscard]] u_ptrExpr makeDoubleExpr(u_ptrToken& _op, const std::string& lex) noexcept;
    [[nodiscard]] u_ptrExpr makeBoolExpr(u_ptrToken& _op) noexcept;
    [[nodiscard]] u_ptrExpr makeStringExpr(u_ptrToken& _op, const std::string& lex) noexcept;
    [[nodiscard]] u_ptrExpr makeIdExpr(DECL exprType, u_ptrToken& _op, const std::string& lex) noexcept;
};

} // Essembly