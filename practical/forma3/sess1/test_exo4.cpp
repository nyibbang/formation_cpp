#include "exo4.hpp"
#include <gtest/gtest.h>

const Complex_type_vector vec {
  { "Hello", 12 },
  { "Ingimates", 23 }
};

TEST(Exo4, ByStr)
{
  EXPECT_EQ(12, find_by_string(vec, "Hello")->i);
  EXPECT_EQ(23, find_by_string(vec, "Ingimates")->i);
  EXPECT_EQ(vec.end(), find_by_string(vec, "Woops"));
}

TEST(Exo4, ByInt)
{
  EXPECT_EQ("Ingimates", find_by_int(vec, 23)->str);
  EXPECT_EQ("Hello", find_by_int(vec, 12)->str);
  EXPECT_EQ(vec.end(), find_by_int(vec, 2318));
}

