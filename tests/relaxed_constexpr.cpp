#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;
using namespace testing;

namespace {

constexpr unsigned long long factorial(unsigned int n) {
  unsigned long long result = 1;
  while (n > 0) {
    result *= n--;
  }
  return result;
}

struct Rational {
  int num, denom;
  constexpr Rational(int num, int denom) : num{num}, denom{denom} {
    if (denom == 0) throw std::logic_error{"Dividing by zero is not cool, man"};
  }
  constexpr Rational(const Rational&) = default;
  constexpr Rational& operator+=(Rational o) {
    Rational new_this{num * o.denom, denom * o.denom};
    o.num *= denom; o.denom *= denom;
    new_this.num += o.num;
    *this = new_this;
    return *this;
  }
  constexpr Rational& operator=(const Rational& o) {
    num = o.num; denom = o.denom;
    return *this;
  }
  constexpr bool operator==(Rational o) const {
    Rational normalized{num * o.denom, denom * o.denom};
    o.num *= denom; o.denom *= denom;
    return normalized.num == o.num && normalized.denom == o.denom;
  }
};


struct Int {
  int value;
  constexpr Int& operator+=(const Int& o) { value += o.value; return *this; }
  constexpr Int& operator/=(const Int& o) { value /= o.value; return *this; }
  constexpr Int& operator=(const Int& o) { value = o.value; return *this; }
  constexpr bool operator==(const Int& o) const { return value == o.value; }
};

constexpr Rational divide_all_and_accumulate_rational(std::initializer_list<int> numbers,
                                             int denom) {
  Rational result{0, 1};
  for (int number : numbers) {
    result += Rational{number, denom};
  }
  return result;
}

constexpr Int divide_all_and_accumulate(std::initializer_list<int> numbers,
                                        int denom) {
  Int result{0};
  for (int number : numbers) {
    Int curr{number};
    if (denom != 0)
      curr /= Int{denom};
    result += curr;
  }
  return result;
}
}

TEST(RelaxedConstexpr, First)
{
  static_assert(factorial(12) == 479001600, "Factorial failed.");
  static_assert(divide_all_and_accumulate_rational({21, 16, 8, -7, 42}, 3) == Rational{80, 3}, "Divide all and accumulate failed");
  static_assert(divide_all_and_accumulate({21, 16, 8, -7, 42}, 3) == Int{26}, "Divide all and accumulate failed");
}
