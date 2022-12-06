#pragma once
#include <string>

namespace Essembly {

enum class TEXPR {
    BYTE,
    SHORT,
    INT,
    FLOAT,
    DOUBLE,
    BOOL,
    STRING,
    BINARY,
    IADD,
    ISUB,
    ADD,
    SUB,
    MUL,
    IMUL,
    DIV,
    IDIV,
    UNARY,
    UNARY_NOT,
    UNARY_MINUS,
    DYNAMIC,
    PRIMARY,
    BINARY
    ID
};

std::string TEXPRtoString(TEXPR);

} // Essembly