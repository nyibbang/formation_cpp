add_executable(tdd_sess3_test test.cpp)
add_test(NAME tdd_sess3_test COMMAND tdd_sess3_test)
target_link_libraries(tdd_sess3_test tdd_sess3_lib gmock_main)
