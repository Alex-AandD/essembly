#include "frontend/include/TypeChecker.hh"
#include "frontend/include/expr.hh"

namespace Essembly {

DECL TypeChecker::binaryHelper(BinaryExpr* expr) {
    // get left and right expressions
    Expr* lhs  = (expr->lhs).get(); /* get the raw pointer */
    Expr* rhs =  (expr ->rhs).get(); /* get the raw pointer*/

    // call recursively the check method
    DECL lhsType = lhs->acceptTypeChecker(this);
    DECL rhsType = rhs->acceptTypeChecker(this);
    
    // TODO: #14 add compare function @Alex-AandD

}


DECL TypeChecker::checkIAddExpr(IAddExpr* expr) {
    /* check recursively the type of the left and right operator */
}

} // ESSEMBLY