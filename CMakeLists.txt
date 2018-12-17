cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

include(cmake/MWSVersion.cmake)
project(
  MWhitespace
  VERSION ${MWS_VERSION}
  DESCRIPTION "Mnemonic Whitespace"
  LANGUAGES CXX)

add_subdirectory(src)
