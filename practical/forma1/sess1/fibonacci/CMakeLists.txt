add_executable(forma1_sess1_fibo fibonacci.hpp fibonacci.cpp test.cpp)
add_test(NAME forma1_sess1_fibo COMMAND forma1_sess1_fibo)
target_link_libraries(forma1_sess1_fibo gmock_main)
