add_executable(forma1_sess1_rpn rpn.hpp rpn.cpp test.cpp)
add_test(NAME forma1_sess1_rpn COMMAND forma1_sess1_rpn)
target_link_libraries(forma1_sess1_rpn gmock_main)
