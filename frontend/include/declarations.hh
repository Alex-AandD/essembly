#pragma once
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
class Token;
class Stmt;
class Visitor;
/* we want to keep the tokens into the expressions */
/* the id is going to store a token to the name */
/* while the actual expressions are going to store a token to the single values */

using u_ptrExpr = std::unique_ptr<Expr>;
using u_ptrStmt = std::unique_ptr<Stmt>;
using u_ptrToken = std::unique_ptr<Token>;

class Stmt {
public:
    Stmt();
    virtual ~Stmt() = 0;
public:
    virtual void accept(Visitor&) = 0;
};

class BlockStmt:  public Stmt {
public:
    u_ptrToken lbrace;
    std::vector<u_ptrStmt> stmts;
    u_ptrToken rbrace;
public:
    BlockStmt(u_ptrToken& lbrace, std::vector<u_ptrStmt>&, u_ptrToken& rbrace);
    ~BlockStmt() override;
public:
    void accept(Visitor&) override;
};

// TODO: #17 add support for if, while, for, fun ... @Alex-AandD

class Declaration: public Stmt {
public:
    u_ptrToken declToken;
    u_ptrExpr idExpr;
    u_ptrExpr valueExpr;
public:
    Declaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~Declaration() override;
public:
    void accept(Visitor& v) override;
};

class IntDeclaration: public Declaration {
public:
    IntDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~IntDeclaration() override;
public:
    void accept(Visitor& v) override;
};

class ShortDeclaration: public Declaration {
public:
    ShortDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~ShortDeclaration() override;
public:
    void accept(Visitor& v) override;
};

class FloatDeclaration: public Declaration {
public:
    FloatDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~FloatDeclaration() override;
public:
    void accept(Visitor& v) override;
};

class StringDeclaration: public Declaration {
public:
    StringDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    virtual ~StringDeclaration() override;
public:
    void accept(Visitor& v) override;
};

class DoubleDeclaration: public Declaration {
public:
    DoubleDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~DoubleDeclaration() override;
public:
    void accept(Visitor& v) override;
};

class BoolDeclaration: public Declaration {
public:
    BoolDeclaration(u_ptrToken&, u_ptrExpr&, u_ptrExpr&);
    ~BoolDeclaration() override;
public:
    void accept(Visitor& v) override;
};

class DynamicDeclaration: public Declaration {
public:
    DynamicDeclaration(u_ptrExpr&, u_ptrExpr&);
    ~DynamicDeclaration() override;
public:
    void accept(Visitor& v) override;
}

} // Essembly