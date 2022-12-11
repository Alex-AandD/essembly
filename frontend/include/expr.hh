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

class DynamicAddExpr: public AddExpr {
public:
    DynamicAddExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DynamicAddExpr() override;
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

class DynamicSubExpr: public SubExpr {
public:
    DynamicSubExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DynamicSubExpr() override;
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

class DynamicMulExpr: public MulExpr {
public:
    DynamicMulExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DynamicMulExpr() override;
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

class DynamicDivExpr: public DivExpr {
public:
    DynamicDivExpr(u_ptrToken& _op, u_ptrExpr&  lhs, u_ptrExpr&  rhs);
    ~DynamicDivExpr() override;
public:
    void accept(Visitor& visitor) override;
};

/*************************************/
/* EQUALITY EXPRESSIONS */
class EqualityExpr: public BinaryExpr {
public:
    EqualityExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~EqualityExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class IEqExpr: public EqualityExpr {
public:
    IEqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~IEqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class SEqExpr: public EqualityExpr {
public:
    SEqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~SEqExpr() override;
public:
    void accept(Visitor& visitor) override;
};
class FEqExpr: public EqualityExpr {
public:
    FEqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~FEqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DEqExpr: public EqualityExpr {
public:
    DEqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~DEqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class StringEqExpr: public EqualityExpr {
public:
    StringEqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~StringEqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class BoolEqExpr: public EqualityExpr {
public:
    BoolEqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~BoolEqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DynamicEqExpr: public EqualityExpr {
    public:
    DynamicEqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~DynamicEqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

// expr != expr
class INeqExpr: public EqualityExpr {
public:
    INeqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~INeqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class SNeqExpr: public EqualityExpr {
public:
    SNeqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~SNeqExpr() override;
public:
    void accept(Visitor& visitor) override;
};
class FNeqExpr: public EqualityExpr {
public:
    FNeqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~FNeqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DNeqExpr: public EqualityExpr {
public:
    DNeqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~DNeqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class StringNeqExpr: public EqualityExpr {
public:
    StringNeqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~StringNeqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class BoolNeqExpr: public EqualityExpr {
public:
    BoolNeqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~BoolNeqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DynamicNeqExpr: public EqualityExpr {
    public:
    DynamicNeqExpr(u_ptrToken&, u_ptrExpr& lhs, u_ptrExpr& rhs);
    ~DynamicNeqExpr() override;
public:
    void accept(Visitor& visitor) override;
};

/***************************/
/***************************/

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
    BoolExpr(u_ptrToken&, bool value);
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
    std::string name;
public:
    IdExpr(u_ptrToken&, const std::string&);
    ~IdExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class IIdExpr: public IdExpr {
public: 
    std::string name;
public:
    IIdExpr(u_ptrToken&, const std::string&);
    ~IIdExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class SIdExpr: public IdExpr {
public: 
    std::string name;
public:
    SIdExpr(u_ptrToken&, const std::string&);
    ~SIdExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class FIdExpr: public IdExpr {
public: 
    std::string name;
public:
    FIdExpr(u_ptrToken&, const std::string&);
    ~FIdExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DIdExpr: public IdExpr {
public: 
    std::string name;
public:
    DIdExpr(u_ptrToken&, const std::string&);
    ~DIdExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class StringIdExpr: public IdExpr {
public: 
    std::string name;
public:
    StringIdExpr(u_ptrToken&, const std::string&);
    ~StringIdExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class BoolIdExpr: public IdExpr {
public: 
    std::string name;
public:
    BoolIdExpr(u_ptrToken&, const std::string&);
    ~BoolIdExpr() override;
public:
    void accept(Visitor& visitor) override;
};

class DynamicIdExpr: public IdExpr {
public: 
    std::string name;
public:
    DynamicIdExpr(u_ptrToken&, const std::string&);
    ~DynamicIdExpr() override;
public:
    void accept(Visitor& visitor) override;
};


} // Essembly