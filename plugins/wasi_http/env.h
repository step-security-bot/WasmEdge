// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2024 Second State INC
#pragma once

#include "plugin/plugin.h"

#include <cstdint>
#include <vector>

namespace WasmEdge {
namespace Host {

class WasiHttpEnvironment {
public:
  WasiHttpEnvironment() noexcept;

  std::string_view loadURI(uint64_t URIIndex) { return URIs[URIIndex]; }

private:
  std::vector<std::string> URIs = {"https://www.google.com/",
                                   "https://duckduckgo.com/"};
};

} // namespace Host
} // namespace WasmEdge
