#pragma once
#include "token.hh"
#include <string>
#include <vector>

class BytecodeVisitor;
class PrintVisitor;

class Expr {
public:
    Expr();
    virtual ~Expr();
public:
    virtual std::string acceptPrintVisitor(PrintVisitor* visitor) = 0;
    virtual void acceptBytecodeVisitor(BytecodeVisitor* visitor) = 0;
};

class BinaryExpr: public Expr {
public:
    Expr* lhs;
    Expr* rhs;
    Token op;
public:
    BinaryExpr(Token op, Expr* lhs, Expr* rhs);
    virtual ~BinaryExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class AddExpr: public BinaryExpr {
public:
    AddExpr(Token _op, Expr* lhs, Expr* rhs);
    virtual ~AddExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class IAddExpr: public AddExpr { 
public:
    IAddExpr(Token _op, Expr* lhs, Expr* rhs);
    ~IAddExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class SubExpr: public BinaryExpr {
public:
    SubExpr(Token _op, Expr* lhs, Expr* rhs);
    virtual ~SubExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class ISubExpr: public SubExpr { 
public:
    ISubExpr(Token _op, Expr* lhs, Expr* rhs);
    ~ISubExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class MulExpr: public BinaryExpr {
public:
    MulExpr(Token _op, Expr* lhs, Expr* rhs);
    virtual ~MulExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class IMulExpr: public MulExpr { 
public:
    IMulExpr(Token _op, Expr* lhs, Expr* rhs);
    ~IMulExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class DivExpr: public BinaryExpr {
public:
    DivExpr(Token _op, Expr* lhs, Expr* rhs);
    virtual ~DivExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class IDivExpr: public DivExpr { 
public:
    IDivExpr(Token _op, Expr* lhs, Expr* rhs);
    ~IDivExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class UnaryExpr: public Expr {
public:
    Expr* expr;
    Token op;
public:
    UnaryExpr(Token, Expr*);
    virtual ~UnaryExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class UnaryNotExpr: public UnaryExpr {
public:
    UnaryNotExpr(Token, Expr*);
    ~UnaryNotExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class UnaryMinusExpr: public UnaryExpr {
public:
    UnaryMinusExpr(Token, Expr*);
    ~UnaryMinusExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};

class IntExpr: public Expr { 
public:
    int value;
public:
    IntExpr(int);
    ~IntExpr() override;
public:
    std::string acceptPrintVisitor(PrintVisitor* visitor) override;
    void acceptBytecodeVisitor(BytecodeVisitor* visitor) override;
};