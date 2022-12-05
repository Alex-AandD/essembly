#include "frontend/include/token.hh"
#include "frontend/include/expr.hh"
#include "backend/include/instruction.hh"
#include "frontend/include/printVisitor.hh"
#include "backend/include/bytecodeVisitor.hh"
#include "frontend/include/TypeChecker.hh"
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

AddExpr::~AddExpr() { }
SubExpr::~SubExpr() { }
MulExpr::~MulExpr() { }
DivExpr::~DivExpr() { }

IAddExpr::IAddExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): AddExpr(_op, l, r) { }
ISubExpr::ISubExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): SubExpr(_op, l, r) { }
IMulExpr::IMulExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): MulExpr(_op, l, r) { }
IDivExpr::IDivExpr(u_ptrToken& _op, u_ptrExpr&  l, u_ptrExpr&  r): DivExpr(_op, l, r) { }

IAddExpr::~IAddExpr() { }
ISubExpr::~ISubExpr() { }
IMulExpr::~IMulExpr() { }
IDivExpr::~IDivExpr() { }

UnaryExpr::UnaryExpr(u_ptrToken& _op, u_ptrExpr&  e): op(std::move(_op)), expr(std::move(e)) { }
UnaryNotExpr::UnaryNotExpr(u_ptrToken& _op, u_ptrExpr&  r): UnaryExpr(_op, r) { } 
UnaryMinusExpr::UnaryMinusExpr(u_ptrToken& _op, u_ptrExpr&  r): UnaryExpr(_op, r) { } 

UnaryExpr::~UnaryExpr() { }
UnaryNotExpr::~UnaryNotExpr() { }
UnaryMinusExpr::~UnaryMinusExpr() { }

IntExpr::IntExpr(int val): value(val) { }
IntExpr::~IntExpr() { }


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

[[nodiscard]] TEXPR IntExpr::getType() const noexcept { return TEXPR::INT; }

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

/* accept methods for typechecking */
[[nodiscard]] DECL BinaryExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkBinaryExpr(this);
}

[[nodiscard]] DECL IAddExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkIAddExpr(this);
}

[[nodiscard]] DECL SubExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkSubExpr(this);
}

[[nodiscard]] DECL ISubExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkISubExpr(this);
}

[[nodiscard]] DECL MulExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkMulExpr(this);
}

[[nodiscard]] DECL IMulExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkIMulExpr(this);
}

[[nodiscard]] DECL DivExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkDivExpr(this);
}

[[nodiscard]] DECL IDivExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkIDivExpr(this);
}

[[nodiscard]] DECL UnaryExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkUnaryExpr(this);
}

[[nodiscard]] DECL UnaryNotExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkUnaryNotExpr(this);
}

[[nodiscard]] DECL UnaryMinusExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkUnaryExpr(this);
}

[[nodiscard]] DECL IntExpr::acceptTypeChecker(TypeChecker* checker) {
    return checker->checkIntExpr(this);
}






} // ESSEMBLY