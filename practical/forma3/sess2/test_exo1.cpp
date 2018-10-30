#include "exo1.hpp"
#include <gtest/gtest.h>

TEST(Exo1, Basic)
{
  std::istringstream input("this is a good day to code i hope everyone is ready"); 
  std::ostringstream output;

  use_algorithms("code", input, output);
  EXPECT_EQ("code;i;hope;everyone;is;ready;this;is;a;good;day;to;", output.str());
}
