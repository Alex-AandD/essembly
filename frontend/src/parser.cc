#include "frontend/include/parser.hh"
#include "frontend/include/token.hh"
#include "frontend/include/expr.hh"
#include "frontend/include/FactoryDeclaration.hh"
#include "frontend/include/declarations.hh"
#include "frontend/include/visitors.hh"
#include <iostream>
#include <vector>

/* USE OF SMART AND RAW POINTERS */
/* FACTORIES CAN RETURN SMART POINTERS */
/* THE EXPRESSIONS THAT MAKE UP THE AST WILL BE SMART POINTERS */
/* VISITORS DO NOT OWN ANYTHING, THEREFORE THEY ONLY GET A RAW POINTER */

namespace Essembly {

Parser::Parser(): 
    factory(std::make_unique<FactoryDeclaration>()), 
    t_current(0),
    l_current(0)
    {
        AST.reserve(10000);
    }


Parser::Parser(std::vector<u_ptrToken>& toks, const std::vector<std::string>& lexemes): 
    tokens(std::move(toks)), 
    lexemes(lexemes), 
    factory(std::make_unique<FactoryDeclaration>()),
    t_current(0), 
    l_current(0) { }

void Parser::printAST(Visitor& visitor) const noexcept {
    for (auto& stmt: AST) {
        stmt -> accept(visitor);
    }
}


[[nodiscard]] u_ptrExpr Parser::makeBinaryExpr(DECL exprType, u_ptrToken& _op, u_ptrExpr& l, u_ptrExpr& r) noexcept {
    switch(_op->type) {
        case TT::PLUS:  return factory->makeAdd(exprType, _op, l, r);
        case TT::MINUS: return factory->makeSub(exprType, _op, l, r);
        case TT::TIMES: return factory->makeMul(exprType, _op, l, r);
        case TT::SLASH: return factory->makeDiv(exprType, _op, l, r);
        default: break;
    }
    return nullptr;
}

[[nodiscard]] u_ptrExpr Parser::makeUnaryExpr(u_ptrToken& _op, u_ptrExpr& r) noexcept {
    return factory->makeUnary(_op, r);
}

void Parser::parse() {
    while (!atEnd()){
        try {
            AST.push_back(stmt());
        } catch(std::exception& e) {
            std::cout << e.what() << '\n';
            // add synchronize function
        }
    }
}

[[nodiscard]] u_ptrStmt Parser::block() {
    // save the left brace for debugging and error handling
    u_ptrToken lbraceToken = previousToken();
    std::vector<u_ptrStmt> stmts;
    while(!atEnd() && !matchCurrent(TT::RIGHT_BRACE)) {
        stmts.push_back(stmt());
    }
    if (atEnd()) assert("missing closing brace opened at some line");
    u_ptrToken rbraceToken = previousToken();
    return makeBlockStmt(lbraceToken, stmts, rbraceToken);
}

[[nodiscard]] u_ptrStmt Parser::makeBlockStmt(u_ptrToken& lbrace, std::vector<u_ptrStmt>& stmts, u_ptrToken& rbrace) noexcept {
    return factory->makeBlockStmt(lbrace, stmts, rbrace);
}

[[nodiscard]] u_ptrStmt Parser::stmt() {
    if (matchCurrent(TT::LEFT_BRACE)) return block();
    /* parse all the other kind of statements */
    return declaration();
}

[[nodiscard]] u_ptrStmt Parser::declaration() {
    /* for now supporting just: 
         int, double, float, bool, string and short
    */
    if (matchCurrent(TT::INT_TYPE)) {
        u_ptrToken declToken = previousToken();
        return finishDeclaration(DECL::INT, declToken);
    }

    if (matchCurrent(TT::BOOL_TYPE)) {
        u_ptrToken declToken = previousToken();
        return finishDeclaration(DECL::BOOL, declToken);
    }

    if (matchCurrent(TT::FLOAT_TYPE)) {
        u_ptrToken declToken = previousToken();
        return finishDeclaration(DECL::FLOAT, declToken);
    }

    if (matchCurrent(TT::DOUBLE_TYPE)) {
        u_ptrToken declToken = previousToken();
        return finishDeclaration(DECL::DOUBLE, declToken);
    }

    if (matchCurrent(TT::SHORT_TYPE)) {
        u_ptrToken declToken = previousToken();
        return finishDeclaration(DECL::SHORT, declToken);
    }

    /* create some kind of intermediate type expression statement, between statement and expression */
    // return expr(DECL::DYNAMIC);
    return dynamicDeclaration(DECL::DYNAMIC);
}

[[nodiscard]] u_ptrStmt Parser::dynamicDeclaration(DECL exprType) {
    u_ptrExpr idExpr = primary(exprType);
    /* check if there is an equal sign */
    if (!matchCurrent(TT::EQ)) {
        // throw an expression
        assert("remember to throw an expression");
    }
    u_ptrExpr valueExpr = expr(exprType);
    return makeDynamicDeclaration(idExpr, valueExpr);
}

[[nodiscard]] u_ptrStmt Parser::finishDeclaration(DECL exprType, u_ptrToken& declToken) {
    /* find the idExpr */
    // if (!matchCurrent(TT::ID)) {
    //     assert("we need an id after the type");
    // }
    /* otherwise we know that this is an expression */
    u_ptrExpr idExpr = primary(exprType);
    /* check if there is an equal sign */
    if (!matchCurrent(TT::EQ)) {
        // throw an expression
        assert("remember to throw an expression");
    }

    /* now get the valueExpr */
    u_ptrExpr valueExpr = expr(exprType);

    /* finally check for a semicolon */
    // TODO: move semicolon check in parent declaration function
    if (!matchCurrent(TT::SEMICOLON)) {
        assert("throw semicolon exception");
    }
    return makeDeclaration(exprType, declToken, idExpr, valueExpr); 
}

[[nodiscard]] u_ptrExpr Parser::expr(DECL exprType) {
    return term(exprType);
}

[[nodiscard]] u_ptrExpr Parser::term(DECL exprType) {
    u_ptrExpr lhs = factor(exprType);
    while (matchCurrent(TT::PLUS, TT::MINUS)) {
        u_ptrToken op = previousToken();
        u_ptrExpr rhs = factor(exprType);
        lhs = makeBinaryExpr(exprType, op, lhs, rhs);
    }
    return lhs;
}

[[nodiscard]] u_ptrExpr Parser::factor(DECL exprType) {
    u_ptrExpr lhs = unary(exprType);
    while (matchCurrent(TT::TIMES, TT::SLASH)) {
        u_ptrToken op = previousToken();
        u_ptrExpr rhs = unary(exprType);
        lhs = makeBinaryExpr(exprType, op, lhs, rhs);
    }
    return lhs;
}

[[nodiscard]] u_ptrExpr Parser::unary(DECL exprType) {
    while(matchCurrent(TT::NOT, TT::MINUS)) {
        u_ptrToken op = previousToken();
        u_ptrExpr rhs = unary(exprType);
        return makeUnaryExpr(op, rhs);
    }
    return primary(exprType);
}

[[nodiscard]] u_ptrStmt Parser::makeDeclaration(DECL type, u_ptrToken& declToken, u_ptrExpr& idExpr, u_ptrExpr& valueExpr) noexcept {
    return factory->makeDeclaration(type, declToken, idExpr, valueExpr);
}

[[nodiscard]] u_ptrStmt Parser::makeDynamicDeclaration(u_ptrExpr& l, u_ptrExpr& r) noexcept {
    return factory->makeDynamicDeclaration(l, r);
}

[[nodiscard]] u_ptrExpr Parser::makeIntegerExpr(DECL exprType) noexcept {
    u_ptrToken exprToken = previousToken();
    u_ptrExpr expr = factory->makeIntegerExpr(exprType, exprToken, currentLexeme());
    advanceLexeme();
    return expr;
}

[[nodiscard]] u_ptrExpr Parser::makeDecimalExpr(DECL exprType) noexcept {
    u_ptrToken exprToken = previousToken();
    u_ptrExpr expr = factory->makeDecimalExpr(exprType, exprToken, currentLexeme());
    advanceLexeme();
    return expr;
}

[[nodiscard]] u_ptrExpr Parser::makeStringExpr() noexcept {
    u_ptrToken exprToken = previousToken();
    u_ptrExpr expr = factory->makeStringExpr(exprToken, currentLexeme());
    advanceLexeme();
    return expr;
}

[[nodiscard]] u_ptrExpr Parser::makeBoolExpr(bool val) noexcept {
    u_ptrToken exprToken = previousToken();
    u_ptrExpr expr = factory->makeBoolExpr(exprToken, val);
    advanceLexeme();
    return expr;
}

[[nodiscard]] u_ptrExpr Parser::makeIdExpr(DECL exprType) noexcept {
    u_ptrToken exprToken = previousToken();
    u_ptrExpr expr = factory->makeIdExpr(exprType, exprToken, currentLexeme());
    advanceLexeme();
    return expr;
}

[[nodiscard]] u_ptrExpr Parser::primary(DECL exprType) {
    if (matchCurrent(TT::INT_LITERAL)) return makeIntegerExpr(exprType);
    if (matchCurrent(TT::FLOAT_LITERAL)) return makeDecimalExpr(exprType);
    if (matchCurrent(TT::STRING_LITERAL)) return makeStringExpr();
    if (matchCurrent(TT::ID)) return makeIdExpr(exprType);
    if (matchCurrent(TT::TRUE_LITERAL)) return makeBoolExpr(true);
    if (matchCurrent(TT::FALSE_LITERAL)) return makeBoolExpr(false);
    else { throw "unknown expression type"; }
}

} // Essembly