#include "frontend/include/TypeChecker.hh"
#include "frontend/include/expr.hh"

namespace Essembly {

[[nodiscard]] static DECL getType(TypeChecker* checker, Expr* expr) {
    return expr->acceptTypeChecker(checker); 
}

[[nodiscard]] DECL TypeChecker::IExprHelper(BinaryExpr* expr) {

    // call recursively the check method
    DECL rhsType = getType(this, expr->rhs.get());
    DECL lhsType = getType(this, expr->lhs.get());
    
    // TODO: #15 find a clever way to check the types @Alex-AandD

}


[[nodiscard]] DECL TypeChecker::checkBinaryExpr(BinaryExpr* expr) {
    // get left and right expressions
    
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