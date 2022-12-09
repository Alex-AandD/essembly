#include "frontend/include/token.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/declarations.hh"
#include "frontend/include/visitors.hh"
#include <vector>

#define ACCEPT_METHOD(exprType) void exprType::accept(Visitor& visitor) { ACCEPT_LOGIC(exprType); }

#define ACCEPT_LOGIC(exprType) do { \
    if (PrintVisitor* pv = dynamic_cast<PrintVisitor*>(&visitor)) { \
        pv->visit##exprType(this); \
    } \
} while(0);

#define ACCEPT_EXPR(exprType) 

namespace Essembly {

Expr::Expr() { }
Expr::~Expr() { }

/* expressions constructors */
BinaryExpr::BinaryExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): op(std::move(_op)), lhs(std::move(l)), rhs(std::move(r)) { }
BinaryExpr::~BinaryExpr(){ };

AddExpr::AddExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): BinaryExpr(_op, l, r) { }
SubExpr::SubExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): BinaryExpr(_op, l, r) { }
MulExpr::MulExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): BinaryExpr(_op, l, r) { }
DivExpr::DivExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): BinaryExpr(_op, l, r) { }

IAddExpr::IAddExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): AddExpr(_op, l, r) { }
ISubExpr::ISubExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): SubExpr(_op, l, r) { }
IMulExpr::IMulExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): MulExpr(_op, l, r) { }
IDivExpr::IDivExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): DivExpr(_op, l, r) { }
SAddExpr::SAddExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): AddExpr(_op, l, r) { }
SSubExpr::SSubExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): SubExpr(_op, l, r) { }
SMulExpr::SMulExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): MulExpr(_op, l, r) { }
SDivExpr::SDivExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): DivExpr(_op, l, r) { }
FAddExpr::FAddExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): AddExpr(_op, l, r) { }
FSubExpr::FSubExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): SubExpr(_op, l, r) { }
FMulExpr::FMulExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): MulExpr(_op, l, r) { }
FDivExpr::FDivExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): DivExpr(_op, l, r) { }
DAddExpr::DAddExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): AddExpr(_op, l, r) { }
DSubExpr::DSubExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): SubExpr(_op, l, r) { }
DMulExpr::DMulExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): MulExpr(_op, l, r) { }
DDivExpr::DDivExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): DivExpr(_op, l, r) { }

EqualityExpr::EqualityExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): BinaryExpr(_op, l, r) { }
IEqExpr::IEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
SEqExpr::SEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
DEqExpr::DEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
FEqExpr::FEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
BoolEqExpr::BoolEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
StringEqExpr::StringEqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }

INeqExpr::INeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
SNeqExpr::SNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
DNeqExpr::DNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
FNeqExpr::FNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
BoolNeqExpr::BoolNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }
StringNeqExpr::StringNeqExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): EqualityExpr(_op, l, r) { }

UnaryExpr::UnaryExpr(u_ptrToken& _op, u_ptrExpr&  e): op(std::move(_op)), expr(std::move(e)) { }
UnaryNotExpr::UnaryNotExpr(u_ptrToken& _op, u_ptrExpr&  r): UnaryExpr(_op, r) { } 
UnaryMinusExpr::UnaryMinusExpr(u_ptrToken& _op, u_ptrExpr&  r): UnaryExpr(_op, r) { } 

PrimaryExpr::PrimaryExpr(u_ptrToken& tok): token(std::move(tok)) { }
IntExpr::IntExpr(u_ptrToken& tok, int val): PrimaryExpr(tok), value(val) { }
FloatExpr::FloatExpr(u_ptrToken& tok, float val): PrimaryExpr(tok), value(val) { }
DoubleExpr::DoubleExpr(u_ptrToken& tok, double val): PrimaryExpr(tok), value(val) { }
ShortExpr::ShortExpr(u_ptrToken& tok, short val): PrimaryExpr(tok), value(val) { }
BoolExpr::BoolExpr(u_ptrToken& tok): PrimaryExpr(tok) { value = tok->type == TT::TRUE_LITERAL; }
IdExpr::IdExpr(u_ptrToken& tok, const std::string& val, DECL _type): PrimaryExpr(tok), name(val), type(_type) { }
StringExpr::StringExpr(u_ptrToken& tok, const std::string& val): PrimaryExpr(tok), value(val) { }

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

/* all the accept methods are defined using a clever macro */

/* declarations */


/* add, sub, mul, div */
ACCEPT_METHOD(BinaryExpr);
ACCEPT_METHOD(AddExpr);
ACCEPT_METHOD(SubExpr);
ACCEPT_METHOD(MulExpr);
ACCEPT_METHOD(DivExpr);
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

/* unary expressions */
ACCEPT_METHOD(UnaryExpr);
ACCEPT_METHOD(UnaryMinusExpr);
ACCEPT_METHOD(UnaryNotExpr);

/* primary expressions */
ACCEPT_METHOD(PrimaryExpr);
ACCEPT_METHOD(BoolExpr);
ACCEPT_METHOD(ShortExpr);
ACCEPT_METHOD(IntExpr);
ACCEPT_METHOD(FloatExpr);
ACCEPT_METHOD(DoubleExpr);
ACCEPT_METHOD(StringExpr);
ACCEPT_METHOD(IdExpr);


} // Essembly