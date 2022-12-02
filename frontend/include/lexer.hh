#pragma once

#include "frontend/include/token.hh"
#include <vector>
#include <string>

class Lexer {
public:
    size_t current;
    size_t start;
    size_t line;
    size_t input_len;
    std::string input;
public:
    std::vector<std::string> lexemes;
    std::vector<Token> tokens;
public:
    Lexer();
    Lexer(std::string _inp);
    ~Lexer();
public:
    void scan();
private:
    /* some helper methods */
    [[nodiscard]] inline bool atEnd() noexcept { return current >= input_len; }
    [[nodiscard]] inline char peekNext() const { return input[current + 1]; }
    [[nodiscard]] inline char peek(size_t offset) const { return input[current + offset]; }
    [[nodiscard]] inline bool isValidVar(char c) { return std::isalpha(c) || c == '_'; }
    [[nodiscard]] inline bool atEnd(size_t offset) noexcept { return current + offset >= input_len; }
    [[nodiscard]] Token createToken(TT type) noexcept;
    [[nodiscard]] bool match(size_t offset, char c) noexcept;
    [[nodiscard]] bool matchNext(char c) noexcept;
    inline void advance() noexcept { current++; }

    inline void pushLexeme(const std::string& lexeme) noexcept { lexemes.push_back(lexeme); }
    void pushToken(TT) noexcept; /* push the token inside the array of tokens */
    void pushString();
    void pushNumber() noexcept;
    void pushFloat() noexcept;
};