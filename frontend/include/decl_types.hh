#pragma once
#include <string>

/* types of declarations used for instruction evaluation and type checking */
namespace Essembly {
enum class DECL {
    INT,
    SHORT,
    FLOAT,
    BOOL,
    DOUBLE,
    FUN,
    METHOD,
    CLASS,
    BYTE
};

std::string DECLtoString(DECL);

}