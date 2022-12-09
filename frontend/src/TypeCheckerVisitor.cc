#include "frontend/include/visitors.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/token.hh";
#include "frontend/include/declarations.hh"

namespace Essembly {


[[nodiscard]] DECL TypeCheckerVisitor::checkUnaryNotExpr(UnaryNotExpr* expr) {
    Expr* rightExpr = (expr->expr).get();
    DECL rightType = rightExpr->acceptTypeCheckerVisitor(this);
    if (rightType != DECL::BOOL) {
        assert("throw, unary not works only with booleans");
    }
}

[[nodiscard]] DECL TypeCheckerVisitor::checkUnaryMinusExpr(UnaryMinusExpr* expr) {
    Expr* rightExpr = (expr->expr).get();
    DECL rightType = rightExpr->acceptTypeCheckerVisitor(this);
    if (rightType != DECL::INT || rightType != DECL::SHORT || rightType != DECL::FLOAT || rightType != DECL::DOUBLE)
        assert("throw, unary minus works only with numeric types");
    }
} // Essembly