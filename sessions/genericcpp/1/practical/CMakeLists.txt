set(genericcpp_sess1_SOURCES cpp14.hpp cpp14.cpp)
set(genericcpp_sess1_test_SOURCES test_cpp14.cpp)
if (cxx_std_17 IN_LIST CMAKE_CXX_COMPILE_FEATURES)
  message(STATUS "The CXX Compiler supports C++17: including C++17 files to GenericCppSess1 targets")
  list(APPEND genericcpp_sess1_SOURCES cpp17.hpp cpp17.cpp)
  list(APPEND genericcpp_sess1_test_SOURCES test_cpp17.cpp)
else()
  message(WARNING "The CXX Compiler does NOT support C++17: excluding C++17 files from GenericCppSess1 targets")
endif()

add_library(
  genericcpp_sess1
  STATIC
    ${genericcpp_sess1_SOURCES}
)
add_executable(genericcpp_sess1_test ${genericcpp_sess1_test_SOURCES})
add_test(NAME genericcpp_sess1_test COMMAND genericcpp_sess1_test)
target_link_libraries(genericcpp_sess1_test genericcpp_sess1 gtest_main)
