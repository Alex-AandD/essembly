#pragma once
#include <string>
#include <memory>

namespace Essembly {
enum class TT {
    PLUS, MINUS, TIMES, SLASH,
    NOT, NEQ, EQE, EQ, LT, LTE, GT, GTE,
    INT_TYPE, INT_LITERAL,
    FLOAT_TYPE, FLOAT_LITERAL,
    DOUBLE_TYPE,
    STRING_TYPE, STRING_LITERAL,
    SHORT_TYPE,
    BOOL_TYPE,
    ID,
    TAB, LF,
    SEMICOLON,
    IF, ELIF,
    WHILE, FOR,
    FUN,
    TRUE_LITERAL, FALSE_LITERAL,
    LEFT_BRACE, RIGHT_BRACE
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