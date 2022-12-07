#include "frontend/include/declarations.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/printVisitor.hh"
#include "backend/include/bytecodeVisitor.hh"
#include "frontend/include/TypeCheckerVisitor.hh"

namespace Essembly
{
Stmt::Stmt() { }
BlockStmt::BlockStmt(u_ptrToken& _lbrace, const std::vector<u_ptrStmt>& _stmts, u_ptrToken& _rbrace):
    lbrace(std::move(_lbrace)), stmts(std::move(_stmts)), rbrace(std::move(_rbrace)) { }
BlockStmt::~BlockStmt() { }

/* constructors */
Declaration::Declaration() { }
Declaration::~Declaration() { }
ValueDeclaration::ValueDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): 
    declToken(std::move(tok)), idExpr(std::move(id)), valueExpr(std::move(value)) { }
IntDeclaration::IntDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): ValueDeclaration(tok, id, value) { };
StringDeclaration::StringDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): ValueDeclaration(tok, id, value) { };
DoubleDeclaration::DoubleDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): ValueDeclaration(tok, id, value) { };
FloatDeclaration::FloatDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): ValueDeclaration(tok, id, value) { };
ShortDeclaration::ShortDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): ValueDeclaration(tok, id, value) { };
BoolDeclaration::BoolDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): ValueDeclaration(tok, id, value) { };

/* destructors */
Declaration::~Declaration() { }
ValueDeclaration::~ValueDeclaration() { }
IntDeclaration::~IntDeclaration() { }

/* bytecode visitor */
void ValueDeclaration::acceptBytecodeVisitor(BytecodeVisitor* visitor) { 
    return visitor->visitValueDeclaration(this);
}

void IntDeclaration::acceptBytecodeVisitor(BytecodeVisitor* visitor) { 
    return visitor->visitIntDeclaration(this);
}

/* type checking */
[[nodiscard]] DECL ValueDeclaration::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    return visitor->checkValueDeclaration(this);
}

[[nodiscard]] DECL IntDeclaration::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    return visitor->checkIntDeclaration(this);
}

/* print visitor */
[[nodiscard]] std::string ValueDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitValueDeclaration(this);
}

[[nodiscard]] std::string IntDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitIntDeclaration(this);
}

} // namespace Essembly
