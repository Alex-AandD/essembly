#include "frontend/include/decl_types.hh"

namespace Essembly {
std::string DECLtoString(DECL declType) {
    switch (declType)
    {
    case DECL::INT: return "INT_DECL";
    case DECL::DOUBLE: return "DOUBLE_DECL";
    case DECL::SHORT: return "SHORT_DECL";
    case DECL::BYTE: return "BYTE_DECL";
    case DECL::BOOL: return "BOOL_DECL";
    case DECL::FLOAT: return "FLOAT_DECL";
    case DECL::METHOD: return "METHOD_DECL";
    case DECL::CLASS: return "_DECL";
    default: return "UNKNOWN TYPE, GO IMPLEMENT IT";
    }
    return nullptr;
}

} // ESSEMBLY
