add_library(sess2_matrix STATIC matrix.hpp matrix.cpp)
add_executable(sess2_matrix_test test.cpp)
add_test(NAME sess2_matrix_test COMMAND sess2_matrix_test)
target_link_libraries(sess2_matrix_test sess2_matrix gtest_main)
