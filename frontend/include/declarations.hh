#pragma once;
#include <memory>
#include <string>
#include <vector>

// we do not check the type of the declarations themselves
// just the expressions that belong to the declarations
// therefore the typechecking of the declarations does not return any value

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
using u_ptrStmt = std::unique_ptr<Stmt>;

class Stmt {
public:
    Stmt();
    virtual ~Stmt() = 0;
    [[nodiscard]] virtual std::string acceptPrintVisitor(PrintVisitor*) = 0;
    virtual void acceptTypeCheckerVisitor(TypeCheckerVisitor*) = 0;
    virtual void acceptBytecodeVisitor(BytecodeVisitor*) = 0;
};

class BlockStmt:  public Stmt {
public:
    u_ptrToken lbrace;
    std::vector<u_ptrStmt> stmts;
    u_ptrToken rbrace;
public:
    BlockStmt(u_ptrToken& lbrace, const std::vector<u_ptrStmt>&, u_ptrToken& rbrace);
    ~BlockStmt() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) = 0;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

// TODO: #17 add support for if, while, for, fun ... @Alex-AandD


/* declarations */
class Declaration: public Stmt {
public:
    Declaration();
    ~Declaration();
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class ValueDeclaration: public Declaration {
public:
    u_ptrToken declToken;
    u_ptrExpr  idExpr;
    u_ptrExpr  valueExpr;
public:
    ValueDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~ValueDeclaration() override;
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class IntDeclaration: public ValueDeclaration {
public:
    IntDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~IntDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class ShortDeclaration: public ValueDeclaration {
public:
    ShortDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~ShortDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class FloatDeclaration: public ValueDeclaration {
public:
    FloatDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~FloatDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class StringDeclaration: public ValueDeclaration {
public:
    StringDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    virtual ~StringDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class DoubleDeclaration: public ValueDeclaration {
public:
    DoubleDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~DoubleDeclaration() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

class BoolDeclaration: public ValueDeclaration {
public:
    BoolDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    virtual ~BoolDeclaration();
public:
    [[nodiscard]] std::string acceptPrintVisitor(PrintVisitor*) override;
    void acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(BytecodeVisitor*) override;
};

} // Essembly