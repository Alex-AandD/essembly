#include "frontend/include/token.hh"
#include "frontend/include/expr.hh"
#include "backend/include/instruction.hh"
#include "frontend/include/printVisitor.hh"
#include "backend/include/bytecodeVisitor.hh"
#include "frontend/include/TypeCheckerVisitor.hh"
#include <vector>

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


UnaryExpr::UnaryExpr(u_ptrToken& _op, u_ptrExpr&  e): op(std::move(_op)), expr(std::move(e)) { }
UnaryNotExpr::UnaryNotExpr(u_ptrToken& _op, u_ptrExpr&  r): UnaryExpr(_op, r) { } 
UnaryMinusExpr::UnaryMinusExpr(u_ptrToken& _op, u_ptrExpr&  r): UnaryExpr(_op, r) { } 

PrimaryExpr::PrimaryExpr(u_ptrToken& tok): token(std::move(tok)) { }
PrimaryExpr::~PrimaryExpr() { }

IntExpr::IntExpr(u_ptrToken& tok, int val): PrimaryExpr(tok), value(val) { }
FloatExpr::FloatExpr(u_ptrToken& tok, float val): PrimaryExpr(tok), value(val) { }
DoubleExpr::DoubleExpr(u_ptrToken& tok, double val): PrimaryExpr(tok), value(val) { }
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
ShortExpr::~ShortExpr() { }
FloatExpr::~FloatExpr() { }
DoubleExpr::~DoubleExpr() { }
StringExpr::~StringExpr() { }
IdExpr::~IdExpr() { }

/* getType implementations */
[[nodiscard]] TEXPR BinaryExpr::getType() const noexcept { return TEXPR::BINARY; }

[[nodiscard]] TEXPR AddExpr::getType() const noexcept { return TEXPR::ADD; }
[[nodiscard]] TEXPR SubExpr::getType() const noexcept { return TEXPR::SUB; }
[[nodiscard]] TEXPR DivExpr::getType() const noexcept { return TEXPR::DIV; }
[[nodiscard]] TEXPR MulExpr::getType() const noexcept { return TEXPR::MUL; }

[[nodiscard]] TEXPR IAddExpr::getType() const noexcept { return TEXPR::IADD; }
[[nodiscard]] TEXPR ISubExpr::getType() const noexcept { return TEXPR::ISUB; }
[[nodiscard]] TEXPR IDivExpr::getType() const noexcept { return TEXPR::IDIV; }
[[nodiscard]] TEXPR IMulExpr::getType() const noexcept { return TEXPR::IMUL; }

[[nodiscard]] TEXPR UnaryExpr::getType() const noexcept { return TEXPR::UNARY; }
[[nodiscard]] TEXPR UnaryMinusExpr::getType() const noexcept { return TEXPR::UNARY_MINUS; }
[[nodiscard]] TEXPR UnaryNotExpr::getType() const noexcept { return TEXPR::UNARY_NOT; }

[[nodiscard]] TEXPR PrimaryExpr::getType() const noexcept { return TEXPR::PRIMARY; }
[[nodiscard]] TEXPR IntExpr::getType() const noexcept { return TEXPR::INT; }
[[nodiscard]] TEXPR IdExpr::getType() const noexcept { return TEXPR::ID; }

/* now the accept methods to print the expression */
[[nodiscard]] std::string BinaryExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitBinaryExpr(this);
}

[[nodiscard]] std::string AddExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitAddExpr(this);
}

[[nodiscard]] std::string IAddExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitIAddExpr(this);
}

[[nodiscard]] std::string ISubExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitISubExpr(this);
}

[[nodiscard]] std::string SubExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitSubExpr(this);
}

[[nodiscard]] std::string MulExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitMulExpr(this);
}

[[nodiscard]] std::string IMulExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitIMulExpr(this);
}

[[nodiscard]] std::string DivExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitDivExpr(this);
}
[[nodiscard]] std::string IDivExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitIDivExpr(this);
}

[[nodiscard]] std::string UnaryExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitUnaryExpr(this);
}

[[nodiscard]] std::string UnaryMinusExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitUnaryMinusExpr(this);
}

[[nodiscard]] std::string UnaryNotExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitUnaryNotExpr(this);
}

[[nodiscard]] std::string IntExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor->visitIntExpr(this);
}

[[nodiscard]] std::string IdExpr::acceptPrintVisitor(ptrPVisitor visitor) {
    return visitor -> visitIdExpr(this);
}

/* now the accept methods to generate the bytecode */
void BinaryExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitBinaryExpr(this);
}

void AddExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitAddExpr(this);
}

void IAddExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitIAddExpr(this);
}

void SubExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitSubExpr(this);
}

void ISubExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitISubExpr(this);
}

void MulExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitMulExpr(this);
}

void IMulExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitIMulExpr(this);
}

void DivExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitDivExpr(this);
}

void IDivExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitIDivExpr(this);
}

void UnaryExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitUnaryExpr(this);
}

void UnaryMinusExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitUnaryMinusExpr(this);
}

void UnaryNotExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitUnaryNotExpr(this);
}

void IntExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitIntExpr(this);
}

void IdExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitIdExpr(this);
}

void StringExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitStringExpr(this);
}

void FloatExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitFloatExpr(this);
}

void ShortExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitShortExpr(this);
}

void BoolExpr::acceptBytecodeVisitor(ptrBVisitor visitor) {
    return visitor->visitBoolExpr(this);
}


/* accept methods for typechecking */
[[nodiscard]] DECL BinaryExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkBinaryExpr(this);
}

[[nodiscard]] DECL IAddExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkIAddExpr(this);
}

[[nodiscard]] DECL SubExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkSubExpr(this);
}

[[nodiscard]] DECL ISubExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkISubExpr(this);
}

[[nodiscard]] DECL MulExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkMulExpr(this);
}

[[nodiscard]] DECL IMulExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkIMulExpr(this);
}

[[nodiscard]] DECL DivExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkDivExpr(this);
}

[[nodiscard]] DECL IDivExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkIDivExpr(this);
}

[[nodiscard]] DECL UnaryExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkUnaryExpr(this);
}

[[nodiscard]] DECL UnaryNotExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkUnaryNotExpr(this);
}

[[nodiscard]] DECL UnaryMinusExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkUnaryExpr(this);
}

[[nodiscard]] DECL IntExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkIntExpr(this);
}

[[nodiscard]] DECL IdExpr::acceptTypeCheckerVisitor(TypeCheckerVisitor* checker) {
    return checker->checkIdExpr(this);
}

} // ESSEMBLY