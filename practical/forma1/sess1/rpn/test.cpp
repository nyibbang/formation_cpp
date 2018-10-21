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

//////////////////////////////////////////////////////////////////////////
/// Detail
//////////////////////////////////////////////////////////////////////////
TEST(RPNDetail, Split)
{
  {
    const auto actual = rpn::detail::split("3 10 5 + *");
    const std::vector<std::string> expected{"3", "10", "5", "+", "*"};
    EXPECT_EQ(expected, actual);
  }

  {
    const auto actual = rpn::detail::split("6 3 - 2 ^ 11 -");
    const std::vector<std::string> expected{"6", "3", "-", "2", "^", "11", "-"};
    EXPECT_EQ(expected, actual);
  }
}

TEST(RPNDetail, SplitMultipleSeparators)
{
  {
    const auto actual = rpn::detail::split("4    3      6    +               *     ");
    const std::vector<std::string> expected{"4", "3", "6", "+", "*"};
    EXPECT_EQ(expected, actual);
  }
}

TEST(RPNDetail, SplitEmpty)
{
  const auto actual = rpn::detail::split("");
  const std::vector<std::string> expected;
  EXPECT_EQ(expected, actual);
}


//////////////////////////////////////////////////////////////////////////
/// A implémenter
//////////////////////////////////////////////////////////////////////////
TEST(RPN, FirstTestCase) // TODO change test case name
{
  // TODO
  FAIL();
}
