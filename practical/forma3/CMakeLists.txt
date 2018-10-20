macro(forma3_add_exo sessnum exonum)
  add_executable(forma3_sess${sessnum}_exo${exonum} exo${exonum}.cpp test_exo${exonum}.cpp)
  add_test(NAME forma3_sess${sessnum}_exo${exonum} COMMAND forma3_sess${sessnum}_exo${exonum})
  target_link_libraries(forma3_sess${sessnum}_exo${exonum} gmock_main)
endmacro()

add_subdirectory(sess1)
add_subdirectory(sess2)
