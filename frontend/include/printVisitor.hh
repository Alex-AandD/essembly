#pragma once

#include <string>
#include <memory>

namespace Essembly {

class PrintVisitor {
public:
    PrintVisitor();
private:
public:
    [[nodiscard]] std::string visitBlockStmt(BlockStmt*);
    [[nodiscard]] std::string visitValueDeclaration(ValueDeclaration*);
    [[nodiscard]] std::string visitIntDeclaration(IntDeclaration*);
    [[nodiscard]] std::string visitIntExpr(IntExpr* expr);
    [[nodiscard]] std::string visitFloatExpr(FloatExpr* expr);
    [[nodiscard]] std::string visitDoubleExpr(DoubleExpr* expr);
    [[nodiscard]] std::string visitBoolExpr(BoolExpr* expr);
    [[nodiscard]] std::string visitStringExpr(StringExpr* expr);
    [[nodiscard]] std::string visitIdExpr(IdExpr* expr);
    [[nodiscard]] std::string visitShortExpr(ShortExpr* expr);
};
}