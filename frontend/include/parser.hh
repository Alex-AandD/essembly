#pragma once
#include "token.hh"
#include "expr_types.hh"
#include <vector>
#include <string>
#include <ctype.h>
#include <memory>
#include "printVisitor.hh"
#include "FactoryExpr.hh"

namespace Essembly {

class Expr;
class FactoryExpr;
class PrintVisitor;

using u_ptrToken = std::unique_ptr<Token>;
using u_ptrExpr =  std::unique_ptr<Expr>;

class Parser { 
private:
    std::vector<u_ptrToken> tokens;
    std::vector<std::string> lexemes;
    u_ptrExpr AST;
    std::unique_ptr<FactoryExpr> factory;
    std::unique_ptr<PrintVisitor> printVisitor;
    size_t t_current; /* index to the current token */
    size_t l_current; /* index to the current lexeme */
public:
    Parser();
    Parser(std::vector<u_ptrToken> tokens, std::vector<std::string> lexemes);
private: /* some helpers */
    [[nodiscard]] inline bool atEnd() { return atEnd(0); }
    [[nodiscard]] inline bool atEnd(size_t offset) { return t_current + offset >= tokens.size(); }
    [[nodiscard]] inline u_ptrToken currentToken() { return getToken(t_current); }
    [[nodiscard]] inline u_ptrToken previousToken() { return getToken(t_current - 1); }
    [[nodiscard]] inline u_ptrToken getToken(size_t position) { return std::move(tokens[position]); }
    [[nodiscard]] inline std::string getLexeme(size_t position) { return lexemes[position]; }
    [[nodiscard]] inline std::string currentLexeme() { return getLexeme(l_current); }
    inline void advanceLexeme () noexcept { l_current++; }

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
    [[nodiscard]] u_ptrExpr parse();
    void printAST() const;
private:
    [[nodiscard]] u_ptrExpr makeBinaryExpr(TEXPR exprType, u_ptrToken&, u_ptrExpr&, u_ptrExpr&) noexcept;
    [[nodiscard]] u_ptrExpr makeUnaryExpr(u_ptrToken&, u_ptrExpr&) noexcept;  
    [[nodiscard]] u_ptrExpr makeIntExpr() noexcept;

    [[nodiscard]] u_ptrExpr expr(TEXPR);
    [[nodiscard]] u_ptrExpr term(TEXPR);
    [[nodiscard]] u_ptrExpr factor(TEXPR);
    [[nodiscard]] u_ptrExpr unary();
    [[nodiscard]] u_ptrExpr primary();
};

template <class T>
[[nodiscard]] bool Parser::match(size_t offset, T type) {
    /* sometimes the offset could lead to bad access */
    /* for now I do not care as I need only offset=0 but in the future this might be necessary */
    if ((!atEnd()) && (tokens[t_current+offset]->type) == type) {
        t_current++;
        return true;
    }
    return false;
}

template <class T, class ...Args>
[[nodiscard]] bool Parser::match(size_t offset, T type, Args... args) {
    return match(offset, type) || match(offset, args...);
}

template <class T, class ...Args>
[[nodiscard]] bool matchCurrent(T first, Args...args) {
    return match(0, first, args...);
}

} // ESSEMBLY