add_executable(generic_tests
  lambdas.cpp
  deduced_return_type.cpp
  relaxed_constexpr.cpp
  template_variables.cpp
  heterogeneous_lookup.cpp
  user_defined_literals.cpp
  attributes.cpp
)
add_test(generic_tests generic_tests)
target_include_directories(generic_tests
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/contrib/googletest/include
    ${CMAKE_BINARY_DIR}/contrib/googletest/include)
target_link_libraries(generic_tests gmock_main)
