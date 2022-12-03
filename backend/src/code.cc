#include "backend/include/code.hh"

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