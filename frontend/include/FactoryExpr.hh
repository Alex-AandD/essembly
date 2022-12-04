#pragma once
#include "expr_types.hh"
#include "token.hh"

namespace Essembly {

class Expr;
class AddExpr;
class MulExpr;
class SubExpr;
class DivExpr;
class UnaryExpr;
class IntExpr;
class FactoryExpr {

using u_ptrExpr = std::unique_ptr<Expr>;
using u_ptrToken = std::unique_ptr<Token>;

public:
    FactoryExpr();
    ~FactoryExpr();
public:
    [[nodiscard]] u_ptrExpr makeAdd(TEXPR, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r);
    [[nodiscard]] u_ptrExpr makeSub(TEXPR, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r);
    [[nodiscard]] u_ptrExpr makeMul(TEXPR, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r);
    [[nodiscard]] u_ptrExpr makeDiv(TEXPR, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r);

    [[nodiscard]] u_ptrExpr makeUnary(u_ptrToken& _op, u_ptrExpr& r) noexcept;
    [[nodiscard]] u_ptrExpr makeInt(std::string lex) noexcept;
};

} // Essembly