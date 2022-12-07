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
[[nodiscard]] void BlockStmt::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    for (const auto& stmt: stmts) {
        stmt->acceptTypeCheckerVisitor(visitor);        
    }
}

[[nodiscard]] void ValueDeclaration::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    // handle ValueDeclaration
}

[[nodiscard]] void IntDeclaration::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    // just check if the valueExpr is correct
    DECL type = valueExpr->acceptTypeCheckerVisitor(visitor);
    if (type != DECL::INT) {
        assert("expected integer type");
    };
}

[[nodiscard]] void FloatDeclaration::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    // just check if the valueExpr is correct
    DECL type = valueExpr->acceptTypeCheckerVisitor(visitor);
    if (type != DECL::FLOAT){
        assert("expected float type");
    };
}

[[nodiscard]] void ShortDeclaration::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    // just check if the valueExpr is correct
    DECL type = valueExpr->acceptTypeCheckerVisitor(visitor);
    if (type != DECL::SHORT){
        assert("expected short type");
    };
}

[[nodiscard]] void DoubleDeclaration::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    // just check if the valueExpr is correct
    DECL type = valueExpr->acceptTypeCheckerVisitor(visitor);
    if (type != DECL::DOUBLE) {
        assert("expected double type");
    };
}

[[nodiscard]] void BoolDeclaration::acceptTypeCheckerVisitor(TypeCheckerVisitor* visitor) {
    // just check if the valueExpr is correct
    DECL type = valueExpr->acceptTypeCheckerVisitor(visitor);
    if (type != DECL::BOOL) {
        assert("expected bool type");
    };
}

/* print visitor */
[[nodiscard]] std::string BlockStmt::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitBlockStmt(this);
}

[[nodiscard]] std::string ValueDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitValueDeclaration(this);
}

[[nodiscard]] std::string IntDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitIntDeclaration(this);
}

[[nodiscard]] std::string DoubleDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitDoubleDeclaration(this);
}

[[nodiscard]] std::string StringDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitStringDeclaration(this);
}

[[nodiscard]] std::string FloatDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitFloatDeclaration(this);
}

[[nodiscard]] std::string BoolDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitBoolDeclaration(this);
}

[[nodiscard]] std::string ShortDeclaration::acceptPrintVisitor(PrintVisitor* visitor) {
    return visitor->visitShortDeclaration(this);
}

} // namespace Essembly
