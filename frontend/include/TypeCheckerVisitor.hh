#pragma once
#include "decl_types.hh"
#include <vector>

namespace Essembly {

class BlockStmt;
class Declaration;
class ValueDeclaration;
class IntDeclaration;
class FloatDeclaration;
class ShortDeclaration;
class DoubleDeclaration;
class StringDeclaration;
class BoolDeclaration;

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
class DoubleExpr;
class ShortExpr;
class BoolExpr;
class StringExpr;
class IdExpr;

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
    DECL IExprHelper(BinaryExpr*);
    DECL SExprHelper(BinaryExpr*);
    DECL FExprHelper(BinaryExpr*);
    DECL DExprHelper(BinaryExpr*);
public:
    void checkBlockStmt(BlockStmt*);
    void checkIntDeclaration(IntDeclaration*);
    void checkShortDeclaration(ShortDeclaration*);
    void checkFloatDeclaration(FloatDeclaration*);
    void checkDoubleDeclaration(DoubleDeclaration*);
    void checkStringDeclaration(StringDeclaration*);
    void checkBoolDeclaration(BoolDeclaration*);

    DECL checkBinaryExpr(BinaryExpr*);
    /* dynamic checking */
    DECL checkAddExpr(AddExpr*);
    DECL checkSubExpr(SubExpr*);
    DECL checkMulExpr(MulExpr*);
    DECL checkDivExpr(DivExpr*);

    DECL checkIAddExpr(IAddExpr*);
    DECL checkISubExpr(ISubExpr*);
    DECL checkIMulExpr(IMulExpr*);
    DECL checkIDivExpr(IDivExpr*);
    DECL checkSAddExpr(SAddExpr*);
    DECL checkSSubExpr(SSubExpr*);
    DECL checkSMulExpr(SMulExpr*);
    DECL checkSDivExpr(SDivExpr*);
    DECL checkFAddExpr(FAddExpr*);
    DECL checkFSubExpr(FSubExpr*);
    DECL checkFMulExpr(FMulExpr*);
    DECL checkFDivExpr(FDivExpr*);
    DECL checkDAddExpr(DAddExpr*);
    DECL checkDSubExpr(DSubExpr*);
    DECL checkDMulExpr(DMulExpr*);
    DECL checkDDivExpr(DDivExpr*);

    DECL checkUnaryExpr(UnaryExpr*);
    DECL checkUnaryNotExpr(UnaryNotExpr*);
    DECL checkUnaryMinusExpr(UnaryMinusExpr*);

    DECL checkIntExpr(IntExpr*); /* for now this is going to be our base case*/
    DECL checkFloatExpr(FloatExpr*); /* for now this is going to be our base case*/
    DECL checkShortExpr(ShortExpr*); /* for now this is going to be our base case*/
    DECL checkDoubleExpr(DoubleExpr*); /* for now this is going to be our base case*/
    DECL checkBoolExpr(BoolExpr*); /* for now this is going to be our base case*/
    DECL checkStringExpr(StringExpr*); /* for now this is going to be our base case*/
    DECL checkIdExpr(IdExpr*); /* for now this is going to be our base case*/
};

} // ESSEMBLY