#include "frontend/include/printVisitor.hh"
#include "frontend/include/token.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/declarations.hh"
#include <string>

namespace Essembly {
PrintVisitor::PrintVisitor() { };

/********************** 
/********************** 
    DECLARATIONS
********************
**********************/


std::string PrintVisitor::visitIntExpr(IntExpr* expr) {
    return std::to_string(expr->value);
}

std::string PrintVisitor::visitIdExpr(IdExpr* expr) {
    return expr->name;
}

std::string PrintVisitor::visitFloatExpr(FloatExpr* expr) {
    return std::to_string(expr->value);
}

std::string PrintVisitor::visitBoolExpr(BoolExpr* expr) {
    return std::to_string(expr->value);
}

std::string PrintVisitor::visitDoubleExpr(DoubleExpr* expr) {
    return std::to_string(expr->value);
}

std::string PrintVisitor::visitStringExpr(StringExpr* expr) {
    return expr->value;
}

std::string PrintVisitor::visitShortExpr(ShortExpr* expr) {
    return std::to_string(expr->value);
}

} // ESSEMBLY