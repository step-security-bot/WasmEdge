// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2024 Second State INC

#include "func.h"
#include "common/defines.h"
#include "common/errcode.h"

#include <cstdint>
#include <string>
#include <vector>

namespace WasmEdge {
namespace Host {

Expect<void> WasiHttpPrint::body(const Runtime::CallingFrame &Frame,
                                 uint32_t StrPtr, uint32_t StrLen) {

  return {};
}

Expect<std::tuple<uint32_t, uint32_t>>
WasiHttpGet::body(const Runtime::CallingFrame &Frame, uint64_t URIIndex) {
  return {};
}

} // namespace Host
} // namespace WasmEdge
