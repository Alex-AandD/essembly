#pragma once
#include "expr_types.hh"
#include "token.hh"

class Expr;
class AddExpr;
class MulExpr;
class SubExpr;
class DivExpr;
class UnaryExpr;
class IntExpr;

class FactoryExpr {
public:
    FactoryExpr();
    ~FactoryExpr();
public:
    [[nodiscard]] Expr* makeAdd(TEXPR, Token _op, Expr* l, Expr* r);
    [[nodiscard]] Expr* makeSub(TEXPR, Token _op, Expr* l, Expr* r);
    [[nodiscard]] Expr* makeMul(TEXPR, Token _op, Expr* l, Expr* r);
    [[nodiscard]] Expr* makeDiv(TEXPR, Token _op, Expr* l, Expr* r);

    [[nodiscard]] Expr* makeUnary(Token _op, Expr* r) noexcept;
    [[nodiscard]] Expr* makeInt(std::string lex) noexcept;
};