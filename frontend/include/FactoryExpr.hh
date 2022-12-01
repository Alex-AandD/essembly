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
    [[nodiscard]] AddExpr* makeAdd(TEXPR, Token _op, Expr* l, Expr* r) noexcept;
    [[nodiscard]] SubExpr* makeSub(TEXPR, Token _op, Expr* l, Expr* r) noexcept;
    [[nodiscard]] MulExpr* makeMul(TEXPR, Token _op, Expr* l, Expr* r) noexcept;
    [[nodiscard]] DivExpr* makeDiv(TEXPR, Token _op, Expr* l, Expr* r) noexcept;

    [[nodiscard]] UnaryExpr* makeUnary(Token _op, Expr* r) noexcept;
    [[nodiscard]] IntExpr* makeInt(std::string lex) noexcept;
};