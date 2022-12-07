#pragma once
#include <string>
#include <memory>

namespace Essembly {
enum class TT {
    PLUS, MINUS, TIMES, SLASH,
    NOT, NEQ, EQE, EQ,
    INT_TYPE, INT_LITERAL,
    FLOAT_TYPE, FLOAT_LITERAL,
    DOUBLE_TYPE, DOUBLE_LITERAL,
    STRING_TYPE, STRING_LITERAL,
    SHORT_TYPE, SHORT_LITERAL,
    BOOL_LITERAL, BOOL_TYPE,
    ID,
    TAB, LF,
    SEMICOLON,
    IF, ELIF,
    WHILE, FOR,
    FUN,
    TRUE_LITERAL, FALSE_LITERAL
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
std::string TokentoString(Token* token);
}