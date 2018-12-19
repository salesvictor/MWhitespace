set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)

message(STATUS "Downloading googletest")
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG master
)
message(STATUS "Downloading googletest - done")

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  message(STATUS "Populating googletest")
  FetchContent_Populate(googletest)
  message(STATUS "Populating googletest - done")
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

include(CTest)

macro(add_gtest TEST_NAME)
  add_executable(${TEST_NAME} ${TEST_NAME}.cc)
  target_link_libraries(${TEST_NAME} gtest gtest_main gmock ${ARGN})
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} --gtest_color=yes)
  set_target_properties(${TEST_NAME} PROPERTIES FOLDER test)
endmacro()

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
