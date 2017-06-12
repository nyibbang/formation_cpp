add_library(sess1_sudoku STATIC sudoku.hpp sudoku.cpp)
add_executable(sess1_sudoku_test test.cpp)
add_test(NAME sess1_sudoku_test COMMAND sess1_sudoku_test)
target_link_libraries(sess1_sudoku_test sess1_sudoku gtest_main)
