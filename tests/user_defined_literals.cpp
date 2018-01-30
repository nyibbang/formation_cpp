#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <chrono>

using namespace std;
using namespace testing;

TEST(UserDefinedLiterals, Chrono)
{
  using namespace std::literals;
  constexpr auto d = 2h + 18min + 33s + 12ms + 9us;
  static_assert(d == 8313012009us, "duration is wrong");
}

TEST(UserDefinedLiterals, String)
{
  using namespace std::literals;
  const auto s = "Hello world"s;
  static_assert(is_same<const string, decltype(s)>::value, "s is not a string");
  assert(s.size() == 11);
}
