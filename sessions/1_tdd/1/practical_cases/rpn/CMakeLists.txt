add_library(tdd_sess1_rpn STATIC rpn.hpp rpn.cpp)
add_executable(tdd_sess1_rpn_test test.cpp)
add_test(NAME tdd_sess1_rpn_test COMMAND tdd_sess1_rpn_test)
target_link_libraries(tdd_sess1_rpn_test tdd_sess1_rpn gtest_main)
