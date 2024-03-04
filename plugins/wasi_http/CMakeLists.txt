# SPDX-License-Identifier: Apache-2.0
# SPDX-FileCopyrightText: 2019-2024 Second State INC

wasmedge_add_library(wasmedgePluginWasiHttp
  SHARED
  env.cpp
  func.cpp
  module.cpp
)

target_compile_options(wasmedgePluginWasiHttp
  PUBLIC
  -DWASMEDGE_PLUGIN
)

target_include_directories(wasmedgePluginWasiHttp
  PUBLIC
  $<TARGET_PROPERTY:wasmedgePlugin,INCLUDE_DIRECTORIES>
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/thirdparty
)

target_link_libraries(wasmedgePluginWasiHttp
  PUBLIC
)
if(WASMEDGE_LINK_PLUGINS_STATIC)
  target_link_libraries(wasmedgePluginWasiHttp
    PRIVATE
    wasmedgeCAPI
  )
else()
  target_link_libraries(wasmedgePluginWasiHttp
    PRIVATE
    wasmedge_shared
  )
endif()

install(TARGETS wasmedgePluginWasiHttp DESTINATION ${CMAKE_INSTALL_LIBDIR}/wasmedge)
