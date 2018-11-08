set( TESTS_SRC test_assembler.cc )

add_executable( test_assembler test_assembler.cc )
include_directories( ${CMAKE_SOURCE_DIR}/src )
target_link_libraries( test_assembler mws gtest_main )
