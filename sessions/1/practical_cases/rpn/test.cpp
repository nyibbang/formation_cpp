#include "rpn.hpp"
#include <gtest/gtest.h>

// Exemples d'expressions d'entrée
//
// "3 4 7 + *"      => 33
// "3 10 5 + *"     => 45
// "42 NEG"         => -42
// "2 1 12 3 / - +" => -1
// "6 3 - 2 ^ 11 -" => -2
//
// Imaginer des cas extrêmes et des cas d'erreurs

TEST(RPN, FirstTestCase) // TODO change test case name
{
  // TODO
}
