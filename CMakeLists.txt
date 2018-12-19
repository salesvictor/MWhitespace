cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

include(cmake/MWSVersion.cmake)
project(
  MWhitespace
  VERSION ${MWS_VERSION}
  DESCRIPTION "Mnemonic Whitespace"
  LANGUAGES CXX)

option(BUILD_MWS_TESTS "Build tests" OFF)
option(BUILD_MWS_DEMOS "Build demos" OFF)

if(BUILD_MWS_TESTS)
  include(${PROJECT_SOURCE_DIR}/cmake/GetGoogleTest.cmake)
endif()

add_subdirectory(src)
