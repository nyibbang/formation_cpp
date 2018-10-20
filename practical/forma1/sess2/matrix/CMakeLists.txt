add_executable(forma1_sess2_matrix matrix.hpp matrix.cpp test.cpp)
add_test(NAME forma1_sess2_matrix COMMAND forma1_sess2_matrix)
target_link_libraries(forma1_sess2_matrix gmock_main)
