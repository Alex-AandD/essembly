#pragma once

#include "token.hh"
#include <vector>
#include <string>
#include <memory>

namespace Essembly {
class Lexer {
public:
    size_t current;
    size_t start;
    size_t line;
    size_t input_len;
    std::string input;
public:
    std::vector<std::string> lexemes;
    std::vector<std::unique_ptr<Token>> tokens;
public:
    Lexer();
    Lexer(std::string _inp);
public:
    void scan();
    inline void reset(const std::string& _inp) { line = 1; current = 0; start = current; input = _inp; input_len = input.size(); }
    inline std::vector<TT> getTokenTypes() const noexcept {
        std::vector<TT> types(tokens.size());
        for (size_t i = 0; i < tokens.size(); i++) {
            types.push_back(tokens[i]->type);
        }
    }
private:
    /* some helper methods */
    [[nodiscard]] inline bool atEnd() noexcept { return current >= input_len; }
    [[nodiscard]] inline char peekNext() const { return input[current + 1]; }
    [[nodiscard]] inline char peek(size_t offset) const { return input[current + offset]; }
    [[nodiscard]] inline bool isValidVar(char c) { return std::isalpha(c) || c == '_'; }
    [[nodiscard]] inline bool atEnd(size_t offset) noexcept { return current + offset >= input_len; }
    [[nodiscard]] std::unique_ptr<Token> createToken(TT type) noexcept;
    [[nodiscard]] bool match(size_t offset, char c) noexcept;
    [[nodiscard]] bool matchNext(char c) noexcept;
    inline void advance() noexcept { current++; }
    inline void pushLexeme(const std::string& lexeme) noexcept { lexemes.push_back(lexeme); }
    void pushToken(TT) noexcept; /* push the token inside the array of tokens */
    void pushString();
    void pushNumber() noexcept;
    void pushFloat() noexcept;
    void pushId();
    void pushKeyword();
};
}