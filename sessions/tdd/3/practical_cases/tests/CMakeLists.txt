add_executable(sess3_test test.cpp)
add_test(NAME sess3_test COMMAND sess3_test)
target_link_libraries(sess3_test sess3_lib gmock_main)
