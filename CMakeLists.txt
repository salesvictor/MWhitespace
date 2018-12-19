cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

include(cmake/MWSVersion.cmake)
project(
  MWhitespace
  VERSION ${MWS_VERSION}
  DESCRIPTION "Mnemonic Whitespace"
  LANGUAGES CXX)

include(CTest)
enable_testing()

add_subdirectory(src)
