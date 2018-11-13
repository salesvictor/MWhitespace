set( TESTS_SRC test_gtest.cc )

add_executable( test_gtest test_gtest.cc )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src )
target_link_libraries( test_gtest gtest_main )
