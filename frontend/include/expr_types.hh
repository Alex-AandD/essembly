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
    DYNAMIC
};

std::string TEXPRtoString(TEXPR);

} // Essembly