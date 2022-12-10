#pragma once
#include "decl_types.hh"

namespace Essembly {

/* first check compatibility for declarations */
[[nodiscard]] bool compatible_with_bool(DECL type) noexcept;
[[nodiscard]] bool compatible_with_string(DECL type) noexcept;
[[nodiscard]] bool compatible_with_numeric(DECL type) noexcept;

[[nodiscard]] bool strictly_compatible_with_short(DECL type) noexcept;
[[nodiscard]] bool strictly_compatible_with_int(DECL type) noexcept;
[[nodiscard]] bool strictly_compatible_with_float(DECL type) noexcept;
[[nodiscard]] bool strictly_compatible_with_double(DECL type) noexcept;

}