# message(AUTHOR_WARNING "No tests to build D:")

include(${PROJECT_SOURCE_DIR}/cmake/GetGoogleTest.cmake)

add_gtest(test_gtest)
