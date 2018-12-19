set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG master
)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()


macro(add_gtest TEST_NAME)
  add_executable(${TEST_NAME} ${TEST_NAME}.cc)
  target_link_libraries(${TEST_NAME} gtest gtest_main gmock ${ARGN})
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
  set_target_properties(${TEST_NAME} PROPERTIES FOLDER test)
endmacro()
