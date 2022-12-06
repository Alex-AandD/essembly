#include "frontend/include/Analyzer.hh"
#include "frontend/include/expr.hh"
#include <iostream>

namespace Essembly
{
    Analyzer::Analyzer(): AST(nullptr), typeChecker(std::make_unique<TypeCheckerVisitor>()) { }
    Analyzer::Analyzer(Expr* _AST): AST(_AST), typeChecker(std::make_unique<TypeCheckerVisitor>()) { }

    void Analyzer::analyze(){
        if (checkTypes()){
            // do something
        }
    }

    bool Analyzer::checkTypes() {
        try
        {
            /* here we will recursively check the type of the expressions */
            DECL type = AST->acceptTypeCheckerVisitor(typeChecker.get());
            return true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
    }
} // namespace Essembly
