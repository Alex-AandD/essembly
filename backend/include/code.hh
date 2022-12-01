#pragma once
#include <cstdint>

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