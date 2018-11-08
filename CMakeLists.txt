cmake_minimum_required( VERSION 3.10 )
project( MWhitespace )

# Compiler Commands
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

# Versioning
set( MWHITESPACES_VERSION_MAJOR 0 )
set( MWHITESPACES_VERSION_MINOR 0 )
set( MWHITESPACES_VERSION_PATCH 0 )
set( MWHITESPACES_VERSION "${MWHITESPACES_VERSION_MAJOR}.${MWHITESPACES_VERSION_MINOR}.${MWHITESPACES_VERSION_PATCH}")

# Adding subdirectories
add_subdirectory( src bin )
add_subdirectory( tests tests )

# Adding gtest as external project
include( ExternalProject )
set_directory_properties( PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/libs )
ExternalProject_Add( googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG master
  CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
             -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=debug_libs
             -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=release_libs
             -Dgtest_force_shared_crt=ON
  INSTALL_COMMAND ""
  LOG_DOWNLOAD ON
  LOG_CONFIGURE ON
  LOG_BUILD ON )
ExternalProject_Get_Property( googletest SOURCE_DIR )
include_directories( ${SOURCE_DIR}/include )
