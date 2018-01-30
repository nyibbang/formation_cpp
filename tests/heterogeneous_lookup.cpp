#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

namespace
{
struct NamedInt {
  int value;
  string name;
  bool operator<(const NamedInt& o) const {
    return make_tuple(value, name) < make_tuple(o.value, o.name);
  }
  friend bool operator<(int a, const NamedInt& b) { return a < b.value; }
  friend bool operator<(const NamedInt& a, int b) { return a.value < b; }
  friend bool operator<(const string& a, const NamedInt& b) { return a < b.name; }
  friend bool operator<(const NamedInt& a, const string& b) { return a.name < b; }
};
}

TEST(HeterogeneousLookup, First)
{
  std::set<NamedInt, less<>> s {{42, "foo"}, {1337, "bar"}};
  ASSERT_NE(end(s), s.find("foo"));
  ASSERT_EQ(42, s.find("foo")->value);
  ASSERT_NE(end(s), s.find(1337));
  ASSERT_EQ("bar", s.find(1337)->name);
}
