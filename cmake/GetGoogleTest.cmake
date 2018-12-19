set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.8.1
)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  message(STATUS "Populating googletest")
  FetchContent_Populate(googletest)
  message(STATUS "Populating googletest - done")
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR}
    EXCLUDE_FROM_ALL)
endif()

include(CTest)
include(GoogleTest)

macro(add_gtest TEST_NAME)
  add_executable(${TEST_NAME} ${TEST_NAME}.cc)
  target_link_libraries(${TEST_NAME}
    PUBLIC gtest gtest_main gmock ${ARGN})
  gtest_discover_tests(
    ${TEST_NAME}
    EXTRA_ARGS --gtest_color=yes
    TEST_PREFIX "${TEST_NAME}."
    PROPERTIES FOLDER "test")
endmacro()

add_custom_target(check
  COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process --output-on-failure)
