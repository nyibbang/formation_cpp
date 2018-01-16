add_library(sess1_rpn STATIC rpn.hpp rpn.cpp)
add_executable(sess1_rpn_test test.cpp)
add_test(NAME sess1_rpn_test COMMAND sess1_rpn_test)
target_link_libraries(sess1_rpn_test sess1_rpn gtest_main)
