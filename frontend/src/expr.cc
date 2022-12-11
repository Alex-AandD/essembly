#include "frontend/include/token.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/declarations.hh"
#include "frontend/include/visitors.hh"
#include <vector>
#include <iostream>

#define ACCEPT_METHOD(exprType) void exprType::accept(Visitor& visitor) { ACCEPT_LOGIC(exprType); }

#define ACCEPT_LOGIC(exprType) do { \
    if (PrintVisitor* pv = dynamic_cast<PrintVisitor*>(&visitor)) { \
        return pv->visit##exprType(this); \
    } \
    else if (TypeVisitor* tv = dynamic_cast<TypeVisitor*>(&visitor)) { \
        return tv->visit##exprType(this); \
    } \
} while(0);

#define ACCEPT_DUMMY(exprType) std::cout << "can't use #exprType accept" << '\n'; exit(1);
#define DUMMY_ACCEPT(exprType) void exprType::accept(Visitor& visitor) { ACCEPT_DUMMY(exprType); }

namespace Essembly {

Expr::Expr() { }
Expr::~Expr() { }
void Expr::accept(Visitor& v) {
    assert("cannot use pure virtual class");
}

/* expressions constructors */
BinaryExpr::BinaryExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): op(std::move(_op)), lhs(std::move(l)), rhs(std::move(r)) { }
BinaryExpr::~BinaryExpr() { };

AddExpr::AddExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): BinaryExpr(_op, l, r) { }
SubExpr::SubExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): BinaryExpr(_op, l, r) { }
MulExpr::MulExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): BinaryExpr(_op, l, r) { }
DivExpr::DivExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): BinaryExpr(_op, l, r) { }

IAddExpr::IAddExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): AddExpr(_op, l, r) { }
ISubExpr::ISubExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): SubExpr(_op, l, r) { }
IMulExpr::IMulExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): MulExpr(_op, l, r) { }
IDivExpr::IDivExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): DivExpr(_op, l, r) { }

SAddExpr::SAddExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): AddExpr(_op, l, r) { }
SSubExpr::SSubExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): SubExpr(_op, l, r) { }
SMulExpr::SMulExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): MulExpr(_op, l, r) { }
SDivExpr::SDivExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): DivExpr(_op, l, r) { }
FAddExpr::FAddExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): AddExpr(_op, l, r) { }
FSubExpr::FSubExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): SubExpr(_op, l, r) { }
FMulExpr::FMulExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): MulExpr(_op, l, r) { }
FDivExpr::FDivExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): DivExpr(_op, l, r) { }
DAddExpr::DAddExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): AddExpr(_op, l, r) { }
DSubExpr::DSubExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): SubExpr(_op, l, r) { }
DMulExpr::DMulExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): MulExpr(_op, l, r) { }
DDivExpr::DDivExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): DivExpr(_op, l, r) { }

DynamicAddExpr::DynamicAddExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): AddExpr(_op, l, r) { }
DynamicSubExpr::DynamicSubExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): SubExpr(_op, l, r) { }
DynamicMulExpr::DynamicMulExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): MulExpr(_op, l, r) { }
DynamicDivExpr::DynamicDivExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): DivExpr(_op, l, r) { }

EqualityExpr::EqualityExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): BinaryExpr(_op, l, r) { }
IEqExpr::IEqExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): EqualityExpr(_op, l, r) { }
SEqExpr::SEqExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): EqualityExpr(_op, l, r) { }
DEqExpr::DEqExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): EqualityExpr(_op, l, r) { }
FEqExpr::FEqExpr(u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r): EqualityExpr(_op, l, r) { }
BoolEqExpr::BoolEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
StringEqExpr::StringEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
DynamicEqExpr::DynamicEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }

INeqExpr::INeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
SNeqExpr::SNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
DNeqExpr::DNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
FNeqExpr::FNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
BoolNeqExpr::BoolNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
StringNeqExpr::StringNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
DynamicNeqExpr::DynamicNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }

UnaryExpr::UnaryExpr(u_ptrToken& _op, u_ptrExpr&  e): op(std::move(_op)), expr(std::move(e)) { }
UnaryNotExpr::UnaryNotExpr(u_ptrToken& _op, u_ptrExpr&  r): UnaryExpr(_op, r) { } 
UnaryMinusExpr::UnaryMinusExpr(u_ptrToken& _op, u_ptrExpr&  r): UnaryExpr(_op, r) { } 

PrimaryExpr::PrimaryExpr(u_ptrToken& tok): token(std::move(tok)) { }
IntExpr::IntExpr(u_ptrToken& tok, int val): PrimaryExpr(tok), value(val) { }
FloatExpr::FloatExpr(u_ptrToken& tok, float val): PrimaryExpr(tok), value(val) { }
DoubleExpr::DoubleExpr(u_ptrToken& tok, double val): PrimaryExpr(tok), value(val) { }
ShortExpr::ShortExpr(u_ptrToken& tok, short val): PrimaryExpr(tok), value(val) { }
BoolExpr::BoolExpr(u_ptrToken& tok, bool val): PrimaryExpr(tok, val) { }
StringExpr::StringExpr(u_ptrToken& tok, const std::string& val): PrimaryExpr(tok), value(val) { }
IdExpr::IdExpr(u_ptrToken& tok, const std::string& val): PrimaryExpr(tok), name(val) { }
IIdExpr::IIdExpr(u_ptrToken& tok, const std::string& val): IdExpr(tok, val) { }
SIdExpr::SIdExpr(u_ptrToken& tok, const std::string& val): IdExpr(tok, val) { }
FIdExpr::FIdExpr(u_ptrToken& tok, const std::string& val):  IdExpr(tok, val) { }
DIdExpr::DIdExpr(u_ptrToken& tok, const std::string& val):  IdExpr(tok, val) { }
StringIdExpr::StringIdExpr(u_ptrToken& tok, const std::string& val):  IdExpr(tok, val) { }
BoolIdExpr::BoolIdExpr(u_ptrToken& tok, const std::string& val):  IdExpr(tok, val) { }
DynamicIdExpr::DynamicIdExpr(u_ptrToken& tok, const std::string& val):  IdExpr(tok, val) { }

/* destructors*/
AddExpr::~AddExpr() { }
SubExpr::~SubExpr() { }
MulExpr::~MulExpr() { }
DivExpr::~DivExpr() { }

IAddExpr::~IAddExpr() { }
ISubExpr::~ISubExpr() { }
IMulExpr::~IMulExpr() { }
IDivExpr::~IDivExpr() { }
SAddExpr::~SAddExpr() { }
SSubExpr::~SSubExpr() { }
SMulExpr::~SMulExpr() { }
SDivExpr::~SDivExpr() { }
DAddExpr::~DAddExpr() { }
DSubExpr::~DSubExpr() { }
DMulExpr::~DMulExpr() { }
DDivExpr::~DDivExpr() { }
FAddExpr::~FAddExpr() { }
FSubExpr::~FSubExpr() { }
FMulExpr::~FMulExpr() { }
FDivExpr::~FDivExpr() { }

DynamicAddExpr::~DynamicAddExpr() { }
DynamicSubExpr::~DynamicSubExpr() { }
DynamicMulExpr::~DynamicMulExpr() { }
DynamicDivExpr::~DynamicDivExpr() { }

IEqExpr::~IEqExpr() { }
SEqExpr::~SEqExpr() { }
DEqExpr::~DEqExpr() { }
FEqExpr::~FEqExpr() { }
BoolEqExpr::~BoolEqExpr() { }
StringEqExpr::~StringEqExpr() { }
DynamicEqExpr::~DynamicEqExpr() { }

INeqExpr::~INeqExpr() { }
SNeqExpr::~SNeqExpr() { }
FNeqExpr::~FNeqExpr() { }
DNeqExpr::~DNeqExpr() { }
BoolNeqExpr::~BoolNeqExpr() { }
StringNeqExpr::~StringNeqExpr() { }
DynamicNeqExpr::~DynamicNeqExpr() { }

UnaryExpr::~UnaryExpr() { }
UnaryNotExpr::~UnaryNotExpr() { }
UnaryMinusExpr::~UnaryMinusExpr() { }

PrimaryExpr::~PrimaryExpr() { }
IntExpr::~IntExpr() { }
BoolExpr::~BoolExpr() { }
ShortExpr::~ShortExpr() { }
FloatExpr::~FloatExpr() { }
DoubleExpr::~DoubleExpr() { }
StringExpr::~StringExpr() { }
IdExpr::~IdExpr() { }
IIdExpr::~IIdExpr() { }
SIdExpr::~SIdExpr() { }
FIdExpr::~FIdExpr() { }
DIdExpr::~DIdExpr() { }
StringIdExpr::~StringIdExpr() { }
BoolIdExpr::~BoolIdExpr() { }
DynamicIdExpr::~DynamicIdExpr() { }

/* add, sub, mul, div */
ACCEPT_METHOD(BinaryExpr);

DUMMY_ACCEPT(AddExpr);
DUMMY_ACCEPT(SubExpr);
DUMMY_ACCEPT(MulExpr);
DUMMY_ACCEPT(DivExpr);

ACCEPT_METHOD(IAddExpr);
ACCEPT_METHOD(ISubExpr);
ACCEPT_METHOD(IDivExpr);
ACCEPT_METHOD(IMulExpr);

ACCEPT_METHOD(SAddExpr);
ACCEPT_METHOD(SSubExpr);
ACCEPT_METHOD(SDivExpr);
ACCEPT_METHOD(SMulExpr);

ACCEPT_METHOD(DAddExpr);
ACCEPT_METHOD(DSubExpr);
ACCEPT_METHOD(DMulExpr);
ACCEPT_METHOD(DDivExpr);

ACCEPT_METHOD(FAddExpr);
ACCEPT_METHOD(FSubExpr);
ACCEPT_METHOD(FMulExpr);
ACCEPT_METHOD(FDivExpr);

/* equality expressions */
ACCEPT_METHOD(IEqExpr);
ACCEPT_METHOD(SEqExpr);
ACCEPT_METHOD(DEqExpr);
ACCEPT_METHOD(FEqExpr);
ACCEPT_METHOD(StringEqExpr);
ACCEPT_METHOD(BoolEqExpr);

ACCEPT_METHOD(INeqExpr);
ACCEPT_METHOD(SNeqExpr);
ACCEPT_METHOD(DNeqExpr);
ACCEPT_METHOD(FNeqExpr);
ACCEPT_METHOD(StringNeqExpr);
ACCEPT_METHOD(BoolNeqExpr);

/* comparison expressions */

/* unary expressions */
ACCEPT_METHOD(UnaryExpr);
ACCEPT_METHOD(UnaryMinusExpr);
ACCEPT_METHOD(UnaryNotExpr);

/* primary expressions */
DUMMY_ACCEPT(PrimaryExpr);
ACCEPT_METHOD(BoolExpr);
ACCEPT_METHOD(TrueExpr);
ACCEPT_METHOD(FalseExpr);
ACCEPT_METHOD(ShortExpr);
ACCEPT_METHOD(IntExpr);
ACCEPT_METHOD(FloatExpr);
ACCEPT_METHOD(DoubleExpr);
ACCEPT_METHOD(StringExpr);

DUMMY_ACCEPT(IdExpr);
ACCEPT_METHOD(IIdExpr);
ACCEPT_METHOD(SIdExpr);
ACCEPT_METHOD(FIdExpr);
ACCEPT_METHOD(DIdExpr);
ACCEPT_METHOD(StringIdExpr);
ACCEPT_METHOD(BoolIdExpr);

ACCEPT_METHOD(DynamicIdExpr);
ACCEPT_METHOD(DynamicEqExpr);
ACCEPT_METHOD(DynamicNeqExpr);
ACCEPT_METHOD(DynamicAddExpr);
ACCEPT_METHOD(DynamicSubExpr);
ACCEPT_METHOD(DynamicMulExpr);
ACCEPT_METHOD(DynamicDivExpr);

} // Essembly