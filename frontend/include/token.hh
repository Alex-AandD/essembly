#pragma once

#include <string>

enum class TT {
    PLUS,
    MINUS,
    TIMES,
    SLASH,
    NOT,
    NEQ,
    INT_TYPE,
    INT_LITERAL,
    FLOAT_TYPE,
    FLOAT_LITERAL,
    STR_TYPE,
    STR_LITERAL,
    ID,
    TAB,
    LF,
    SEMICOLON,
};

struct Token {
    TT type;
    size_t line;
    size_t offset;
    std::string mod;
public:
    Token(TT type, size_t off, size_t line, std::string mod);
    ~Token();
};

/* print the lexeme of the token */
std::string TokentoString(const Token& token);