add_executable(forma1_sess3 test.cpp)
add_test(NAME forma1_sess3 COMMAND forma1_sess3)
target_link_libraries(forma1_sess3 forma1_sess3_utils gmock_main)
