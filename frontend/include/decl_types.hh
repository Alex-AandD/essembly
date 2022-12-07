#pragma once
#include <string>

/* types of declarations used for instruction evaluation and type checking */
namespace Essembly {
enum class DECL {
    BYTE    =    1,
    BOOL    =    2,
    SHORT   =    3,
    FUN     =    4,
    METHOD  =    5,
    CLASS   =    6,
    INT     =    7, 
    STRING  =    8,    
    DYNAMIC =    9,
    FLOAT   =   15,
    DOUBLE  =   31,
};

std::string DECLtoString(DECL);

}