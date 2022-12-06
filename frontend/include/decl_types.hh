#pragma once
#include <string>

/* types of declarations used for instruction evaluation and type checking */
namespace Essembly {
enum class DECL {
    BYTE    =    1,
    BOOL    =    2,
    SHORT   =    3,
    FUN     =    4,
    INT     =    7, 
    FLOAT   =   15,
    DOUBLE  =   31,
    METHOD  =    5,
    CLASS   =    6,
};

std::string DECLtoString(DECL);

}