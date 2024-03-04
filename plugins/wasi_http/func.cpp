// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2024 Second State INC

#include "func.h"
#include "common/defines.h"
#include "common/errcode.h"

#include <cpr/cpr.h>
#include <cstdint>
#include <string>
#include <vector>

namespace WasmEdge {
namespace Host {

Expect<void> WasiHttpPrint::body(const Runtime::CallingFrame &, uint32_t,
                                 uint32_t) {
  return {};
}

Expect<uint32_t> WasiHttpGet::body(const Runtime::CallingFrame &,
                                   uint64_t URIIndex) {
  auto URI = Env.loadURI(URIIndex);

  cpr::Response r = cpr::Get(
      cpr::Url{URI}, cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC});
  spdlog::info("status: {}", r.status_code);
  spdlog::info("content type: {}", r.header["content-type"]);
  spdlog::info("text: {}", r.text);

  return r.status_code;
}

} // namespace Host
} // namespace WasmEdge
