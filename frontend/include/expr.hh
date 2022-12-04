#pragma once
#include "token.hh"
#include <string>
#include <vector>
#include <memory>


namespace Essembly {

    class BytecodeVisitor;
    class PrintVisitor;
    class Expr;

    using ptrPVisitor = PrintVisitor*;
    using ptrBVisitor = BytecodeVisitor*;
    using u_ptrPVisitor = std::unique_ptr<PrintVisitor>;
    using u_ptrBVisitor = std::unique_ptr<BytecodeVisitor>;
    using u_ptrExpr = std::unique_ptr<Expr>;
    using u_ptrToken = std::unique_ptr<Token>;

class Expr {
public:
    Expr();
    virtual ~Expr();
public:
    [[nodiscard]] virtual std::string acceptPrintVisitor(ptrPVisitor) = 0;
    virtual void acceptBytecodeVisitor(ptrBVisitor) = 0;
};

class BinaryExpr: public Expr {
public:
    u_ptrExpr lhs;
    u_ptrExpr rhs;
    u_ptrToken op;
public:
    BinaryExpr(u_ptrToken& op, u_ptrExpr& lhs, u_ptrExpr& rhs);
    virtual ~BinaryExpr();
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor visitor) override;
    void acceptBytecodeVisitor(ptrBVisitor  visitor) override;
};

class AddExpr: public BinaryExpr {
public:
    AddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~AddExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class IAddExpr: public AddExpr { 
public:
    IAddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IAddExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class SubExpr: public BinaryExpr {
public:
    SubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~SubExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class ISubExpr: public SubExpr { 
public:
    ISubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~ISubExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor  visitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class MulExpr: public BinaryExpr {
public:
    MulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~MulExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class IMulExpr: public MulExpr { 
public:
    IMulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IMulExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class DivExpr: public BinaryExpr {
public:
    DivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DivExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class IDivExpr: public DivExpr { 
public:
    IDivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IDivExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class UnaryExpr: public Expr {
public:
    u_ptrExpr  expr;
    u_ptrToken op;
public:
    UnaryExpr(u_ptrToken&, u_ptrExpr&);
    ~UnaryExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor visitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class UnaryNotExpr: public UnaryExpr {
public:
    UnaryNotExpr(u_ptrToken&, u_ptrExpr& );
    ~UnaryNotExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class UnaryMinusExpr: public UnaryExpr {
public:
    UnaryMinusExpr(u_ptrToken&, u_ptrExpr& );
    ~UnaryMinusExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class IntExpr: public Expr { 
public:
    int value;
public:
    IntExpr(int);
    ~IntExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};
} // Essembly