#pragma once
#include "decl_types.hh"
#include <vector>

namespace Essembly {

class Expr;
class BinaryExpr;
class UnaryExpr;

class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;

class IAddExpr;
class ISubExpr;
class IMulExpr;
class IDivExpr;
class SAddExpr;
class SSubExpr;
class SMulExpr;
class SDivExpr;
class FAddExpr;
class FSubExpr;
class FMulExpr;
class FDivExpr;
class DAddExpr;
class DSubExpr;
class DMulExpr;
class DDivExpr;

class IntExpr;
class FloatExpr;
class DoubleEXpr;
class BoolExpr;

class UnaryNotExpr;
class UnaryMinusExpr;

/* the TypeCheckerVisitor is not going to return anything */
/* it is just going to emit errors */
/* only dynamic types will be resolved */
/* how is this checking going to happen? */

/* two methods for binary */
/* check right and check left */
/* recursively check the type of the expression */

class TypeCheckerVisitor {
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
    [[nodiscard]] DECL checkSAddExpr(SAddExpr*);
    [[nodiscard]] DECL checkSSubExpr(SSubExpr*);
    [[nodiscard]] DECL checkSMulExpr(SMulExpr*);
    [[nodiscard]] DECL checkSDivExpr(SDivExpr*);
    [[nodiscard]] DECL checkFAddExpr(FAddExpr*);
    [[nodiscard]] DECL checkFSubExpr(FSubExpr*);
    [[nodiscard]] DECL checkFMulExpr(FMulExpr*);
    [[nodiscard]] DECL checkFDivExpr(FDivExpr*);
    [[nodiscard]] DECL checkDAddExpr(DAddExpr*);
    [[nodiscard]] DECL checkDSubExpr(DSubExpr*);
    [[nodiscard]] DECL checkDMulExpr(DMulExpr*);
    [[nodiscard]] DECL checkDDivExpr(DDivExpr*);

    [[nodiscard]] DECL checkUnaryExpr(UnaryExpr*);
    [[nodiscard]] DECL checkUnaryNotExpr(UnaryNotExpr*);
    [[nodiscard]] DECL checkUnaryMinusExpr(UnaryMinusExpr*);

    [[nodiscard]] DECL checkIntExpr(IntExpr*); /* for now this is going to be our base case*/
    [[nodiscard]] DECL checkFloatExpr(FloatExpr*); /* for now this is going to be our base case*/
    [[nodiscard]] DECL checkShortExpr(ShortExpr*); /* for now this is going to be our base case*/
    [[nodiscard]] DECL checkDoubleExpr(DoubleExpr*); /* for now this is going to be our base case*/
    [[nodiscard]] DECL checkBoolExpr(BoolExpr*); /* for now this is going to be our base case*/
    [[nodiscard]] DECL checkStringExpr(StringExpr*); /* for now this is going to be our base case*/
    [[nodiscard]] DECL checkIdExpr(IdExpr*); /* for now this is going to be our base case*/

};

} // ESSEMBLY