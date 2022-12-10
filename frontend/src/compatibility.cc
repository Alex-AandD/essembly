#include "frontend/include/compatibility.hh"

namespace Essembly {

[[nodiscard]] bool compatible_with_bool(DECL type) noexcept {
    return type == DECL::BOOL;
}

[[nodiscard]] bool compatible_with_string(DECL type) noexcept {
    return type == DECL::STRING;
}

[[nodiscard]] bool compatible_with_numeric(DECL type) noexcept {
    return type == DECL::DOUBLE || type == DECL::FLOAT || type == DECL::INT || type == DECL::SHORT;
}

/*******************************************************************/
/*******************************************************************/

[[nodiscard]] bool strictly_compatible_with_short(DECL type) noexcept {
    return type == DECL::SHORT;
}

[[nodiscard]] bool strictly_compatible_with_int(DECL type) noexcept {
    return type == DECL::INT || type == DECL::SHORT;
}

[[nodiscard]] bool strictly_compatible_with_float(DECL type) noexcept {
    return type == DECL::FLOAT || type == DECL::INT || type == DECL::SHORT;
}


} // Essembly