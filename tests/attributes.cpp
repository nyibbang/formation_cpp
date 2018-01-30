#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

namespace
{

[[deprecated("dude, stop using this")]]
void make_coffee(int n) {}

void foo(int a, [[deprecated]] double b) {
  cout << a << b;
}

struct A
{
  [[deprecated]] int old_member {-1};
  long long a {};
};

struct [[deprecated]] OldA {};

}

TEST(Attributes, DeprecatedFunction)
{
  make_coffee(42);
}

TEST(Attributes, DeprecatedParam)
{
  foo(42, 12.);
}

TEST(Attributes, DeprecatedStruct)
{
  OldA a;
}

TEST(Attributes, DeprecatedMember)
{
  A a;
  cout << a.old_member << endl;
}
