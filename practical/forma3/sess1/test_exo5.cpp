#include "exo5.hpp"
#include <gtest/gtest.h>

TEST(Exo5, Basic)
{
  EXPECT_ANY_THROW(do_stuff());
  EXPECT_TRUE(allocated_resources.empty());
}
