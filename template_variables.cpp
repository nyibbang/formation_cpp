#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;
using namespace testing;

namespace {

template<typename T>
constexpr T pi = T(3.1415926535897932385);

}

TEST(TemplateVariables, First)
{
  static_assert(pi<int> == 3, "Pi is not 3");
  static_assert(pi<double> - 3.1415 < 0.0001, "Pi is not 3.1415");
}
