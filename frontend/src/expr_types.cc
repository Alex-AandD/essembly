#pragma once
#include <string>

namespace Essembly {
    std::string TEXPRtoString(TEXPR type) {
        switch (type) {
            case TEXPR::BOOL: return "BOOL_EXPR";
            case TEXPR::BYTE: return "BYTE_EXPR";
            case TEXPR::DOUBLE: return "DOUBLE_EXPR";
            case TEXPR::FLOAT: return "FLOAT_EXPR";
            case TEXPR::STRING: return "STRING_EXPR";
            case TEXPR::SHORT: return "SHORT_EXPR";
            case TEXPR::DYNAMIC: return "DYNAMIC_EXPR";
            case TEXPR::PRIMARY: return "PRIMARY_EXPR";
            default: return "UNKNOWN TYPE, GO IMPLEMENT IT";
        }
        return nullptr;
    }


} // ESSEMBLY