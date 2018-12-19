message(STATUS "Configuring mws version: ${MWS_VERSION}")

add_library(mws
  src/assembler.cc
  src/mws.cc)

set_target_properties(mws PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(mws
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PUBLIC $<INSTALL_INTERFACE:include>
  PRIVATE src)

target_compile_options(mws
  PRIVATE -Wall -Wextra)
target_compile_options(mws
  PUBLIC $<$<CONFIG:DEBUG>: -g>
  PUBLIC $<$<CONFIG:RELEASE>: -O2>)

add_library(mws::mws ALIAS mws)

if(BUILD_MWS_TESTS)
  message(STATUS "Configuring mws unit tests")
  add_subdirectory(test ${CMAKE_BINARY_DIR}/test)
  message(STATUS "Configuring mws unit tests - done")
endif()

if(BUILD_MWS_DEMOS)
  message(STATUS "Configuring mws demos")
  add_subdirectory(demo ${CMAKE_BINARY_DIR}/demo)
  message(STATUS "Configuring mws demos - done")
endif()

message(STATUS "Configuring mws version: ${MWS_VERSION} - done")
