message(STATUS "Configuring mws version: ${MWS_VERSION}")

add_library(mws
  src/)

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

if(BUILD_TESTS)
  message(STATUS "Configuring unit tests")
  add_subdirectory(test ${CMAKE_BINARY_DIR}/test)
  message(STATUS "Configuring unit tests - done")
endif()

if(BUILD_DEMOS)
  message(STATUS "Configuring demos")
  add_subdirectory(demo ${CMAKE_BINARY_DIR}/demo)
  message(STATUS "Configuring demos - done")
endif()
