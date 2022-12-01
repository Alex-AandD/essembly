#include "frontend/include/token.hh"
#include "frontend/include/expr.hh"
#include "backend/include/instruction.hh"
#include "frontend/include/printVisitor.hh"
#include "backend/include/bytecodeVisitor.hh"
#include <vector>

Expr::Expr() { }
Expr::~Expr() { }

/* expressions constructors */
BinaryExpr::BinaryExpr(Token _op, Expr* l, Expr* r): op(_op), lhs(l), rhs(r) { }
BinaryExpr::~BinaryExpr() {
    if (lhs) {
        delete lhs;
        lhs = nullptr;
    }
    if (rhs) {
        delete rhs;
        rhs = nullptr;
    }
}

AddExpr::AddExpr(Token _op, Expr* l, Expr* r): BinaryExpr(_op, l, r) { }
SubExpr::SubExpr(Token _op, Expr* l, Expr* r): BinaryExpr(_op, l, r) { }
MulExpr::MulExpr(Token _op, Expr* l, Expr* r): BinaryExpr(_op, l, r) { }
DivExpr::DivExpr(Token _op, Expr* l, Expr* r): BinaryExpr(_op, l, r) { }

AddExpr::~AddExpr() { }
SubExpr::~SubExpr() { }
MulExpr::~MulExpr() { }
DivExpr::~DivExpr() { }

IAddExpr::IAddExpr(Token _op, Expr* l, Expr* r): AddExpr(_op, l, r) { }
IAddExpr::~IAddExpr() {
    if (lhs) {
        delete lhs;
        lhs = nullptr;
    }
    if (rhs) {
        delete rhs;
        rhs = nullptr;
    }
}

ISubExpr::ISubExpr(Token _op, Expr* l, Expr* r): SubExpr(_op, l, r) { }
ISubExpr::~ISubExpr() {
    if (lhs) {
        delete lhs;
        lhs = nullptr;
    }
    if (rhs) {
        delete rhs;
        rhs = nullptr;
    }
}

IMulExpr::IMulExpr(Token _op, Expr* l, Expr* r): MulExpr(_op, l, r) { }
IMulExpr::~IMulExpr() {
    if (lhs) {
        delete lhs;
        lhs = nullptr;
    }
    if (rhs) {
        delete rhs;
        rhs = nullptr;
    }
}

IDivExpr::IDivExpr(Token _op, Expr* l, Expr* r): DivExpr(_op, l, r) { }
IDivExpr::~IDivExpr() {
    if (lhs) {
        delete lhs;
        lhs = nullptr;
    }
    if (rhs) {
        delete rhs;
        rhs = nullptr;
    }
}

UnaryExpr::UnaryExpr(Token _op, Expr* e): op(_op), expr(e) { }
UnaryExpr::~UnaryExpr() {
    if (expr) {
        delete expr;
        expr = nullptr;
    }
}

UnaryNotExpr::UnaryNotExpr(Token _op, Expr* r): UnaryExpr(_op, r) { } 
UnaryNotExpr::~UnaryNotExpr() {
    if (expr) {
        delete expr;
        expr = nullptr;
    }
}

std::string UnaryNotExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitUnaryNotExpr(this);
}

UnaryMinusExpr::UnaryMinusExpr(Token _op, Expr* r): UnaryExpr(_op, r) { } 
UnaryMinusExpr::~UnaryMinusExpr() {
    if (expr) {
        delete expr;
        expr = nullptr;
    }
} 

std::string UnaryMinusExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitUnaryMinusExpr(this);
}

IntExpr::IntExpr(int val): value(val) { }
IntExpr::~IntExpr() { }

/* now the accept methods to print the expression */
std::string BinaryExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitBinaryExpr(this);
}

std::string IAddExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitIAddExpr(this);
}

std::string ISubExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitISubExpr(this);
}

std::string IMulExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitIMulExpr(this);
}

std::string IDivExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitIDivExpr(this);
}

std::string UnaryExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitUnaryExpr(this);
}

std::string IntExpr::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitIntExpr(this);
}

/* now the accept methods to generate the bytecode */
void BinaryExpr::acceptBytecodeVisitor(BytecodeVisitor* visitor) {
    return visitor->visitBinaryExpr(this);
}

void IAddExpr::acceptBytecodeVisitor(BytecodeVisitor* visitor) {
    return visitor->visitIAddExpr(this);
}

void ISubExpr::acceptBytecodeVisitor(BytecodeVisitor* visitor) {
    return visitor->visitISubExpr(this);
}

void IMulExpr::acceptBytecodeVisitor(BytecodeVisitor* visitor) {
    return visitor->visitIMulExpr(this);
}

void IDivExpr::acceptBytecodeVisitor(BytecodeVisitor* visitor) {
    return visitor->visitIDivExpr(this);
}

void UnaryExpr::acceptBytecodeVisitor(BytecodeVisitor* visitor) {
    return visitor->visitUnaryExpr(this);
}

void IntExpr::acceptBytecodeVisitor(BytecodeVisitor* visitor) {
    return visitor->visitIntExpr(this);
}