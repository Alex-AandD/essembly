#include "frontend/include/TypeCheckerVisitor.hh"
#include "frontend/include/expr.hh"

namespace Essembly {

[[nodiscard]] static DECL getType(TypeCheckerVisitor* checker, Expr* expr) {
    return expr->acceptTypeCheckerVisitor(checker); 
}

/* SMALL NOTE */
/* here in the compatible functions we are passing the biggest type */
/* the other type is compatible if it is smaller or equal in size */
[[nodiscard]] static bool are_compatible(DECL lhs, DECL rhs) {
    switch(lhs) {
        case DECL::INT: return compatible_with_int(rhs);
        case DECL::SHORT: return compatible_with_short(rhs);
        case DECL::DOUBLE: return compatible_with_double(rhs);
        case DECL::FLOAT: return compatible_with_float(rhs);
        case DECL::BYTE: return compatible_with_byte(rhs);
        default: assert("missing declaration type for compatibility");
    }
    return false;
}

[[nodiscard]] static bool compatible_with_float(DECL decl) {
    return decl == DECL::FLOAT;
}

[[nodiscard]] static bool compatible_with_double(DECL decl) {
    return decl == DECL::DOUBLE || decl == DECL::FLOAT;
}

[[nodiscard]] static bool compatible_with_int(DECL decl) {
    return decl == DECL::INT || decl == DECL::SHORT || decl == DECL::BYTE;
}

[[nodiscard]] static bool compatible_with_short(DECL decl) {
    return decl == DECL::SHORT || decl == DECL::BYTE;
}

[[nodiscard]] static bool compatible_with_byte(DECL decl) {
    return decl == DECL::BYTE;
}

[[nodiscard]] DECL TypeCheckerVisitor::IExprHelper(BinaryExpr* expr) {

    // call recursively the check method
    DECL rhsType = getType(this, expr->rhs.get());
    DECL lhsType = getType(this, expr->lhs.get());
    
    // TODO: #15 find a clever way to check the types @Alex-AandD
    // for now just a switch statement. Something better at a later point
    if (!compatible_with_int(rhsType)) {
        assert("type error not implemented yet for rhs");
    }

    if (!compatible_with_int(lhsType)) {
        assert("type error not implemented yet for lhs");
    }
    /* if the types are good then just return */
    return DECL::INT;
}

[[nodiscard]] DECL TypeCheckerVisitor::SExprHelper(BinaryExpr* expr) {

    // call recursively the check method
    DECL rhsType = getType(this, expr->rhs.get());
    DECL lhsType = getType(this, expr->lhs.get());
    
    // TODO: #15 find a clever way to check the types @Alex-AandD
    // for now just a switch statement. Something better at a later point
    if (!compatible_with_short(rhsType)) {
        assert("type error not implemented yet for rhs");
    }

    if (!compatible_with_short(lhsType)) {
        assert("type error not implemented yet for lhs");
    }
    /* if the types are good then just return */
    return DECL::SHORT;
}

[[nodiscard]] DECL TypeCheckerVisitor::FExprHelper(BinaryExpr* expr) {

    // call recursively the check method
    DECL rhsType = getType(this, expr->rhs.get());
    DECL lhsType = getType(this, expr->lhs.get());
    
    // TODO: #15 find a clever way to check the types @Alex-AandD
    // for now just a switch statement. Something better at a later point
    if (!compatible_with_float(rhsType)) {
        assert("type error not implemented yet for rhs");
    }

    if (!compatible_with_float(lhsType)) {
        assert("type error not implemented yet for lhs");
    }
    /* if the types are good then just return */
    return DECL::FLOAT;
}

[[nodiscard]] DECL TypeCheckerVisitor::DxprHelper(BinaryExpr* expr) {

    // call recursively the check method
    DECL rhsType = getType(this, expr->rhs.get());
    DECL lhsType = getType(this, expr->lhs.get());
    
    // TODO: #15 find a clever way to check the types @Alex-AandD
    // for now just a switch statement. Something better at a later point
    if (!compatible_with_double(rhsType)) {
        assert("type error not implemented yet for rhs");
    }

    if (!compatible_with_double(lhsType)) {
        assert("type error not implemented yet for lhs");
    }
    /* if the types are good then just return */
    return DECL::DOUBLE;
}

[[nodiscard]] DECL getBiggestType(DECL first, DECL second) {
    if (first > second) return first;
    return second;
}

[[nodiscard]] DECL TypeCheckerVisitor::checkBinaryExpr(BinaryExpr* expr) {
    DECL lhs = getType(this, expr->lhs.get());
    DECL rhs = getType(this, expr->rhs.get());

    // TODO: #14 add compare function @Alex-AandD
    if (lhs == rhs) return lhs;
    if (lhs != rhs) /* here we are checking the code in the enum */ {
        if (are_compatible(lhs, rhs)) return getBiggestType(lhs, rhs);
        assert("if they are not compatible just return an error");
    }
}

/* dynamic binary expressions */
[[nodiscard]] DECL TypeCheckerVisitor::checkAddExpr(AddExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeCheckerVisitor::checkSubExpr(SubExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeCheckerVisitor::checkMulExpr(MulExpr* expr) {
    return checkBinaryExpr(expr);
}

[[nodiscard]] DECL TypeCheckerVisitor::checkDivExpr(DivExpr* expr) {
    return checkBinaryExpr(expr);
}

/* integer expressions */
[[nodiscard]] DECL TypeCheckerVisitor::checkIAddExpr(IAddExpr* expr) {
    /* check recursively the type of the left and right operator */
    return IExprHelper(expr);
}


[[nodiscard]] DECL TypeCheckerVisitor::checkISubExpr(ISubExpr* expr) {
    return IExprHelper(expr);
}


[[nodiscard]] DECL TypeCheckerVisitor::checkIMulExpr(IMulExpr* expr) {
    return IExprHelper(expr);
}


[[nodiscard]] DECL TypeCheckerVisitor::checkIDivExpr(IDivExpr* expr) {
    return IExprHelper(expr);
}

/* primary expressions */
[[nodiscard]] DECL TypeCheckerVisitor::checkIntExpr(IntExpr* expr) {
    return DECL::INT;
}

[[nodiscard]] DECL TypeCheckerVisitor::checkStringExpr(StringExpr* expr) {
    return DECL::STRING;
}

[[nodiscard]] DECL TypeCheckerVisitor::checkFloatExpr(FloatExpr* expr) {
    return DECL::FLOAT;
}

[[nodiscard]] DECL TypeCheckerVisitor::checkDoubleExpr(DoubleExpr* expr) {
    return DECL::DOUBLE;
}

[[nodiscard]] DECL TypeCheckerVisitor::checkShortExpr(ShortExpr* expr) {
    return DECL::SHORT;
}

[[nodiscard]] DECL TypeCheckerVisitor::checkBoolExpr(BoolExpr* expr) {
    return DECL::BOOL;
}

[[nodiscard]] DECL TypeCheckerVisitor::checkIdExpr(IdExpr* expr) {
    return expr->type;
}

} // ESSEMBLY