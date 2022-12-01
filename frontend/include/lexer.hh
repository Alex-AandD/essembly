#pragma once

#include "frontend/include/token.hh"
#include <vector>
#include <string>

class Lexer {
private:
    size_t current;
    size_t start;
    size_t line;
    size_t input_len;
    std::string input;
public:
    std::vector<std::string> lexemes;
    std::vector<Token> tokens;
public:
    Lexer(std::string _inp);
    ~Lexer();
public:
    void scan();
private:
    [[nodiscard]] inline bool atEnd() noexcept {
        return current >= input_len;
    }
    [[nodiscard]] Token createToken(TT type) noexcept;
    [[nodiscard]] inline char peekNext() const {
        return input[current + 1];
    }
    [[nodiscard]] inline bool isValidVar(char c) { return std::isalpha(c) || c == '_'; }
    inline void advance() noexcept { current++; }
    /* creating new tokens and lexemes and adding them to the array */
    void pushToken(TT) noexcept; /* push the token inside the array of tokens */
    void pushLexeme(const std::string& lexeme) noexcept { lexemes.push_back(lexeme); }
    void pushString();
    void pushNumber() noexcept;
    void pushFloat() noexcept;
};