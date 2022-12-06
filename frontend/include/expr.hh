#pragma once
#include "token.hh"
#include "expr_types.hh"
#include "decl_types.hh"
#include <string>
#include <vector>
#include <memory>

/* each expression manages memory using a unique pointer */
/* this means that copying an expression would result into an error. Expressions can only be movable */
/* therefore copy constructor and assignment are deleted */

namespace Essembly {

    class BytecodeVisitor;
    class PrintVisitor;
    class Expr;
    class TypeCheckerVisitor;

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
    Expr(const Expr&) = delete;
    Expr& operator=(const Expr&) = delete;
public: // helper virtual methods
    [[nodiscard]] virtual TEXPR getType() const noexcept = 0;
public:
    /* visitors */
    [[nodiscard]] virtual std::string acceptPrintVisitor(ptrPVisitor) = 0;
    [[nodiscard]] virtual DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) = 0;
    virtual void acceptBytecodeVisitor(ptrBVisitor  visitor) = 0;
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
    [[nodiscard]] TEXPR getType() const noexcept override;
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor visitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(ptrBVisitor visitor) override;

};

class AddExpr: public BinaryExpr {
public:
    AddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~AddExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class IAddExpr: public AddExpr { 
public:
    IAddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IAddExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class SubExpr: public BinaryExpr {
public:
    SubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~SubExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class ISubExpr: public SubExpr { 
public:
    ISubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~ISubExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor  visitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class MulExpr: public BinaryExpr {
public:
    MulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~MulExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class IMulExpr: public MulExpr { 
public:
    IMulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IMulExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
};

class DivExpr: public BinaryExpr {
public:
    DivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DivExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class IDivExpr: public DivExpr { 
public:
    IDivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IDivExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
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
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class UnaryNotExpr: public UnaryExpr {
public:
    UnaryNotExpr(u_ptrToken&, u_ptrExpr& );
    ~UnaryNotExpr() override;
public:
    [[nodiscard]] TEXPR getType() const noexcept override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class UnaryMinusExpr: public UnaryExpr {
public:
    UnaryMinusExpr(u_ptrToken&, u_ptrExpr& );
    ~UnaryMinusExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class PrimaryExpr: public Expr {
public:
    u_ptrToken token;
public:
    PrimaryExpr(u_ptrToken&);
    ~PrimaryExpr() override;
private:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};

class IntExpr: public PrimaryExpr { 
public:
    int value;
public:
    IntExpr(u_ptrToken&, int);
    ~IntExpr() override;
public:
    [[nodiscard]] std::string acceptPrintVisitor(ptrPVisitor) override;
    [[nodiscard]] TEXPR getType() const noexcept override;
    [[nodiscard]] DECL acceptTypeCheckerVisitor(TypeCheckerVisitor*) override;
    void acceptBytecodeVisitor(ptrBVisitor) override;
};
} // Essembly