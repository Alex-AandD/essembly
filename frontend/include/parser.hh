#pragma once
#include "token.hh"
#include "expr_types.hh"
#include <vector>
#include <string>

class Expr;
class BinaryExpr;
class UnaryExpr;
class IntExpr;

class Parser { 
private:
    std::vector<Token> tokens;
    std::vector<std::string> lexemes;
    Expr* AST;
    FactoryExpr factory;
    size_t current;
public:
    Parser(std::vector<Token> tokens, std::vector<std::string> lexemes);
    ~Parser();
private: /* some helpers */
    [[nodiscard]] inline Token currentToken() { return getToken(current); }
    [[nodiscard]] inline Token previousToken() { return getToken(current - 1); }
    [[nodiscard]] inline Token getToken(size_t position) { return tokens[position]; }
    [[nodiscard]] inline std::string getLexeme(size_t position) { return lexemes[position]}
    [[nodiscard]] inline std::string currentLexeme() { return getLexeme(current); }

    /* some helper functions */
    template <class T, class ...Args>
    [[nodiscard]] bool match(size_t offset, T first, Args... args);
    template <class T>
    [[nodiscard]] bool match(size_t offset, T first);

    template <class T, class ...Args>
    [[nodiscard]] bool matchCurrent(T first, Args...args) {
        return match(0, first, args...);
    }
public:
    [[nodiscard]] Expr* parse();
private:
    [[nodiscard]] Expr* makeBinaryExpr(TEXPR exprType, Token, Expr*, Expr*) noexcept;
    [[nodiscard]] Expr* makeUnaryExpr(Token, Expr*) noexcept;  
    [[nodiscard]] Expr* makeIntExpr() noexcept;

    [[nodiscard]] Expr* expr(TEXPR);
    [[nodiscard]] Expr* term(TEXPR);
    [[nodiscard]] Expr* factor(TEXPR);
    [[nodiscard]] Expr* unary();
    [[nodiscard]] Expr* primary();
};

template <class T>
[[nodiscard]] bool Parser::match(size_t offset, T type) {
    /* sometimes the offset could lead to bad access */
    /* for now I do not care as I need only offset=0 but in the future this might be necessary */
    if (tokens[current + offset].type == type) {
        current++;
        return true
    }
    return false;
}

template <class T, class ...Args>
[[nodiscard]] bool Parser::match(size_t offset, T type, Args... args) {
    return match(offset, type) || match(offset, args...);
}

template <class T, class ...Args>
[[nodiscard]] bool matchCurrent(T first, Args...args) {
    return match(0, first, args);
}