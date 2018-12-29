include(${PROJECT_SOURCE_DIR}/cmake/GetGoogleTest.cmake)

add_gtest(test_gtest)
add_gtest(test_assembler mws::mws)
add_gtest(test_utils mws::mws)
