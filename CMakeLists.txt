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

# Download and unpack gtest at configure time
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/libs/CMakeLists.txt.in
  ${CMAKE_CURRENT_BINARY_DIR}/libs/src/googletest-download/CMakeLists.txt )
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libs/src/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libs/src/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(
  ${CMAKE_CURRENT_BINARY_DIR}/libs/src/googletest
  ${CMAKE_CURRENT_BINARY_DIR}/libs/src/googletest-build
  EXCLUDE_FROM_ALL )
