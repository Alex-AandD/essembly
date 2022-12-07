#pragma once;
#include <memory>
#include <string>

namespace Essembly {
/* Declaration class */
/* type of declarations */
/*
    Function
    int
    double
    bool 
    byte
    string
    class
    method
    ...
*/
/* every declaration is going to have a declaration token */
/* and an expression, which is going to contain the token of the expression and the value (or another expression) */

class Expr;
class BytecodeVisitor;
class PrintVisitor;
class TypeCheckerVisitor;
/* we want to keep the tokens into the expressions */
/* the id is going to store a token to the name */
/* while the actual expressions are going to store a token to the single values */

using u_ptrExpr = std::unique_ptr<Expr>;

class Declaration {
public:
    Declaration();
    virtual ~Declaration() = 0;
public:
    [[nodiscard]] virtual std::string acceptPrintVisitor(PrintVisitor*) = 0;
    [[nodiscard]] virtual DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) = 0;
    virtual void acceptBytecodeVisitor(BytecodeVisitor*) = 0;
};

class ValueDeclaration: public Declaration {
    u_ptrExpr  idExpr;
    u_ptrExpr  valueExpr;
public:
    ValueDeclaration(u_ptrToken, u_ptrExpr);
    ~ValueDeclaration() override;
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class IntDeclaration: public ValueDeclaration {
public:
    IntDeclaration(u_ptrToken, u_ptrExpr);
    ~IntDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class ShortDeclaration: public ValueDeclaration {
public:
    ShortDeclaration(u_ptrToken, u_ptrExpr);
    ~ShortDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class FloatDeclaration: public ValueDeclaration {
public:
    FloatDeclaration(u_ptrToken, u_ptrExpr);
    ~FloatDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class StringDeclaration: public ValueDeclaration {
public:
    StringDeclaration(u_ptrToken, u_ptrExpr);
    virtual ~StringDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class DoubleDeclaration: public ValueDeclaration {
public:
    DoubleDeclaration(u_ptrToken, u_ptrExpr);
    ~DoubleDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class BoolDeclaration: public ValueDeclaration {
public:
    BoolDeclaration(u_ptrToken, u_ptrExpr);
    virtual ~BoolDeclaration();
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

} // Essembly