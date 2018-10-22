#include "exo1.hpp"
#include <gtest/gtest.h>

TEST(Exo1, Int)
{
  EXPECT_EQ("int: 42", print(42));
}

TEST(Exo1, Double)
{
  EXPECT_EQ("double: 3.14", print(3.14));
}

TEST(Exo1, String)
{
  EXPECT_EQ("string: hello ingima", print("hello ingima"));
}

TEST(Exo1, Nullptr)
{
  EXPECT_EQ("null", print(nullptr));
}
