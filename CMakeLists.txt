cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

set(MWS_ROOT ${CMAKE_CURRENT_BINARY_DIR})

include(cmake/MWSVersion.cmake)
project(
  MWhitespace
  VERSION ${MWS_VERSION}
  DESCRIPTION "Mnemonic Whitespace"
  LANGUAGES CXX)

option(BUILD_MWS_TESTS "Build mws tests" OFF)
option(BUILD_MWS_DEMOS "Build mws demos" OFF)

add_subdirectory(mws tmp)
