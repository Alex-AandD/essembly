#pragma once
#include "decl_types.hh"
#include <vector>

namespace Essembly {

class Expr;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class IAddExpr;
class ISubExpr;
class IMulExpr;
class IDivExpr;
class IntExpr;
class BinaryExpr;
class UnaryExpr;
class UnaryNotExpr;
class UnaryMinusExpr;

/* the typechecker is not going to return anything */
/* it is just going to emit errors */
/* only dynamic types will be resolved */
/* how is this checking going to happen? */

/* two methods for binary */
/* check right and check left */
/* recursively check the type of the expression */

class TypeChecker {
private:
    [[nodiscard]] DECL IExprHelper(BinaryExpr*);
public:
    [[nodiscard]] DECL checkBinaryExpr(BinaryExpr*);

    /* dynamic checking */
    [[nodiscard]] DECL checkAddExpr(AddExpr*);
    [[nodiscard]] DECL checkSubExpr(SubExpr*);
    [[nodiscard]] DECL checkMulExpr(MulExpr*);
    [[nodiscard]] DECL checkDivExpr(DivExpr*);

    [[nodiscard]] DECL checkIAddExpr(IAddExpr*);
    [[nodiscard]] DECL checkISubExpr(ISubExpr*);
    [[nodiscard]] DECL checkIMulExpr(IMulExpr*);
    [[nodiscard]] DECL checkIDivExpr(IDivExpr*);

    [[nodiscard]] DECL checkUnaryExpr(UnaryExpr*);
    [[nodiscard]] DECL checkUnaryNotExpr(UnaryNotExpr*);
    [[nodiscard]] DECL checkUnaryMinusExpr(UnaryMinusExpr*);

    [[nodiscard]] DECL checkIntExpr(IntExpr*); /* for now this is going to be our base case*/
};

} // ESSEMBLY