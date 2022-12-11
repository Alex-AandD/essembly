#include "frontend/include/declarations.hh"
#include "frontend/include/visitors.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/token.hh"
#include <vector>

#define ACCEPT_METHOD(stmtType) void stmtType::accept(Visitor& visitor) { ACCEPT_LOGIC(stmtType); }

#define ACCEPT_LOGIC(stmtType) do { \
    if (PrintVisitor* pv = dynamic_cast<PrintVisitor*>(&visitor)) { \
        pv->visit##stmtType(this); \
    } \
} while(0);

namespace Essembly
{

using u_ptrToken = std::unique_ptr<Token>;
using u_ptrExpr = std::unique_ptr<Expr>;
using u_ptrStmt = std::unique_ptr<Stmt>;

Stmt::Stmt() { }
Stmt::~Stmt() { }

BlockStmt::BlockStmt(u_ptrToken& _lbrace, std::vector<u_ptrStmt>& _stmts, u_ptrToken& _rbrace):
    lbrace(std::move(_lbrace)), stmts(std::move(stmts)), rbrace(std::move(_rbrace)) {
}
BlockStmt::~BlockStmt() { }

/* constructors */
Declaration::Declaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): 
    declToken(std::move(tok)), idExpr(std::move(id)), valueExpr(std::move(value)) { }
IntDeclaration::IntDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): Declaration(tok, id, value) { };
StringDeclaration::StringDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): Declaration(tok, id, value) { };
DoubleDeclaration::DoubleDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): Declaration(tok, id, value) { };
FloatDeclaration::FloatDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): Declaration(tok, id, value) { };
ShortDeclaration::ShortDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): Declaration(tok, id, value) { };
BoolDeclaration::BoolDeclaration(u_ptrToken& tok, u_ptrExpr& id, u_ptrExpr& value): Declaration(tok, id, value) { };
DynamicDeclaration::DynamicDeclaration(u_ptrExpr& id, u_ptrExpr& value): Declaration(nullptr, id, value) { };

/* destructors */
Declaration::~Declaration() { }
IntDeclaration::~IntDeclaration() { }
DoubleDeclaration::~DoubleDeclaration() { }
StringDeclaration::~StringDeclaration() { }
FloatDeclaration::~FloatDeclaration() { }
ShortDeclaration::~ShortDeclaration() { }
BoolDeclaration::~BoolDeclaration() { }
DynamicDeclaration::~DynamicDeclaration() { }

/* ACCEPT METHODS */
ACCEPT_METHOD(BlockStmt);
ACCEPT_METHOD(Declaration);
ACCEPT_METHOD(BoolDeclaration);
ACCEPT_METHOD(ShortDeclaration);
ACCEPT_METHOD(IntDeclaration);
ACCEPT_METHOD(FloatDeclaration);
ACCEPT_METHOD(DoubleDeclaration);
ACCEPT_METHOD(StringDeclaration);
ACCEPT_METHOD(DynamicDeclaration);

} // namespace Essembly
