#pragma once
#include "expr_types.hh"
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
class InDECL;
class BinaryExpr;

/* the typechecker is not going to return anything */
/* it is just going to emit errors */
/* only dynamic types will be resolved */
/* how is this checking going to happen? */

/* two methods for binary */
/* check right and check left */
/* recursively check the type of the expression */

class TypeChecker {
private:
    DECL binaryHelper(BinaryExpr*);
public:
    /* dynamic checking */
    DECL checkAddExpr(AddExpr*);
    DECL checkSubExpr(SubExpr*);
    DECL checkMulExpr(SubExpr*);
    DECL checkDivExpr(SubExpr*);

    DECL checkIAddExpr(IAddExpr*);
    DECL checkISubExpr(ISubExpr*);
    DECL checkIMulExpr(IMulExpr*);
    DECL checkIDivExpr(IDivExpr*);

    DECL checkInt(InDECL*); /* for now this is going to be our base case*/
};

} // ESSEMBLY