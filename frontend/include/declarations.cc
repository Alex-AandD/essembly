#include "frontend/include/declarations.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/printVisitor.hh"
#include "backend/include/bytecodeVisitor.hh"
#include "frontend/include/TypeCheckerVisitor.hh"

namespace Essembly
{

/* constructors */
Declaration::Declaration() { }
ValueDeclaration::ValueDeclaration(u_ptrToken tok, u_ptrExpr value): declToken(std::move(tok)), valueExpr(std::move(value)) { }
IntDeclaration::IntDeclaration(u_ptrToken tok, u_ptrExpr value): ValueDeclaration(tok, value) { };

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
