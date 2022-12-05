#include "frontend/include/TypeChecker.hh"
#include "frontend/include/expr.hh"

namespace Essembly {

[[nodiscard]] DECL TypeChecker::checkBinaryExpr(BinaryExpr* expr) {
    // get left and right expressions
    Expr* lhs  = (expr->lhs).get(); /* get the raw pointer */
    Expr* rhs =  (expr ->rhs).get(); /* get the raw pointer*/

    // call recursively the check method
    DECL lhsType = lhs->acceptTypeChecker(this);
    DECL rhsType = rhs->acceptTypeChecker(this);
    
    // TODO: #14 add compare function @Alex-AandD
}

[[nodiscard]] DECL TypeChecker::checkAddExpr(AddExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeChecker::checkIAddExpr(IAddExpr* expr) {
    /* check recursively the type of the left and right operator */
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeChecker::checkSubExpr(SubExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeChecker::checkISubExpr(ISubExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeChecker::checkMulExpr(MulExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeChecker::checkIMulExpr(IMulExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeChecker::checkDivExpr(DivExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeChecker::checkIDivExpr(IDivExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeChecker::checkIntExpr(IntExpr* expr) {
    return DECL::INT;
}


} // ESSEMBLY