#pragma once
#include <cstdint>
#include <string>

enum class CODE: uint8_t {
    IPUSH   =   0x1,
    IPOP    =   0x2,
    IADD    =   0x3,
    ISUB    =   0x4,
    IMUL    =   0x5,
    IDIV    =   0x6,
    ILOAD   =   0x7, 
    ISTORE  =   0x8,
};

/* use the string version of the code for the disassembly part */
[[nodiscard]] std::string CodetoString(CODE code) {
    switch(code) {
        case CODE::IADD: return "IADD";
        case CODE::IPOP: return "IPOP";
        case CODE::IPUSH: return "IPUSH";
        case CODE::ILOAD: return "ILOAD";
        case CODE::IDIV: return "IDIV";
        case CODE::ISTORE: return "ISTORE";
        case CODE::IMUL: return "IMUL";
        case CODE::ISUB: return "ISUB";
        default: return "UNKNOWN CODE, ADD IT TO THE LIST OF CODES";
    }
}