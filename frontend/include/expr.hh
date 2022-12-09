#pragma once
#include "expr_types.hh"
#include "decl_types.hh"
#include <string>
#include <vector>
#include <memory>

/* each expression manages memory using a unique pointer */
/* this means that copying an expression would result into an error. Expressions can only be movable */
/* therefore copy constructor and assignment are deleted */

namespace Essembly {

    class Visitor;
    class Expr;
    class Token;

    using u_ptrExpr = std::unique_ptr<Expr>;
    using u_ptrToken = std::unique_ptr<Token>;

class Expr {
public:
    Expr();
    virtual ~Expr() = 0;
    Expr(const Expr&) = delete;
    Expr& operator=(const Expr&) = delete;
public:
    virtual void accept(Visitor&) = 0;
};


class BinaryExpr: public Expr {
public:
    u_ptrExpr lhs;
    u_ptrExpr rhs;
    u_ptrToken op;
public:
    BinaryExpr(u_ptrToken& op, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~BinaryExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class AddExpr: public BinaryExpr {
public:
    AddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~AddExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class IAddExpr: public AddExpr { 
public:
    IAddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IAddExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class FAddExpr: public AddExpr { 
public:
    FAddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~FAddExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DAddExpr: public AddExpr { 
public:
    DAddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DAddExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class SAddExpr: public AddExpr { 
public:
    SAddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~SAddExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class SubExpr: public BinaryExpr {
public:
    SubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~SubExpr() override;
public:
    void accept(Visitor& visitor) override;
};

/* sub expressions */
class ISubExpr: public SubExpr { 
public:
    ISubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~ISubExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class FSubExpr: public SubExpr { 
public:
    FSubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~FSubExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DSubExpr: public SubExpr { 
public:
    DSubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DSubExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class SSubExpr: public SubExpr { 
public:
    SSubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~SSubExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class MulExpr: public BinaryExpr {
public:
    MulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~MulExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class IMulExpr: public MulExpr { 
public:
    IMulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IMulExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class FMulExpr: public MulExpr { 
public:
    FMulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~FMulExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DMulExpr: public MulExpr { 
public:
    DMulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DMulExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class SMulExpr: public MulExpr { 
public:
    SMulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~SMulExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DivExpr: public BinaryExpr {
public:
    DivExpr(u_ptrToken& _op, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~DivExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class IDivExpr: public DivExpr { 
public:
    IDivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~IDivExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class FDivExpr: public DivExpr { 
public:
    FDivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~FDivExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class SDivExpr: public DivExpr { 
public:
    SDivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~SDivExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DDivExpr: public DivExpr { 
public:
    DDivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DDivExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class UnaryExpr: public Expr {
public:
    u_ptrExpr  expr;
    u_ptrToken op;
public:
    UnaryExpr(u_ptrToken&, u_ptrExpr&);
    ~UnaryExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class UnaryNotExpr: public UnaryExpr {
public:
    UnaryNotExpr(u_ptrToken&, u_ptrExpr& );
    ~UnaryNotExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class UnaryMinusExpr: public UnaryExpr {
public:
    UnaryMinusExpr(u_ptrToken&, u_ptrExpr&);
    ~UnaryMinusExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class PrimaryExpr: public Expr {
public:
    u_ptrToken token;
public:
    PrimaryExpr(u_ptrToken&);
    ~PrimaryExpr() override;
private:
    void accept(Visitor& visitor) override;
};

class IntExpr: public PrimaryExpr { 
public:
    int value;
public:
    IntExpr(u_ptrToken&, int);
    ~IntExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class ShortExpr: public PrimaryExpr { 
public:
    short value;
public:
    ShortExpr(u_ptrToken&, short);
    ~ShortExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class BoolExpr: public PrimaryExpr { 
public:
    bool value;
public:
    BoolExpr(u_ptrToken&);
    ~BoolExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class FloatExpr: public PrimaryExpr { 
public:
    float value;
public:
    FloatExpr(u_ptrToken&, float);
    ~FloatExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DoubleExpr: public PrimaryExpr { 
public:
    double value;
public:
    DoubleExpr(u_ptrToken&, double);
    ~DoubleExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class StringExpr: public PrimaryExpr {
public:
    std::string value;
public:
    StringExpr(u_ptrToken&, const std::string&);
    ~StringExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class IdExpr: public PrimaryExpr {
public: 
    DECL type;
    std::string name;
public:
    IdExpr(u_ptrToken&, const std::string&, DECL);
    ~IdExpr() override;
public:
    void accept(Visitor& visitor) override;
};

} // Essembly