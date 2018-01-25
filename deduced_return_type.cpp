#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

namespace
{

// Implémentations arbitraires de do_something_impl, juste pour l'exemple
std::string do_something_impl(int v) {
  return std::to_string(v);
}
bool do_something_impl(std::pair<std::string, int> v) {
  return v.first == std::to_string(v.second);
}
// ... Potentiellement d'autres implémentations  non triviales de do_something_impl

template<typename T>
auto do_something(T t) { // Type de retour non trivial
    return do_something_impl(t);
}

template<typename Proc, typename ProcBefore, typename ProcAfter>
auto wrap(Proc p, ProcBefore before, ProcAfter after) {
  return [=]() mutable {
    before();
    p();
    after();
  };
}

struct CallableMock
{
  MOCK_METHOD0(before, void());
  MOCK_METHOD0(call, void());
  MOCK_METHOD0(after, void());

  void operator()() {
    return call();
  }
};

}

TEST(DeducedReturnType, First)
{
  ASSERT_TRUE(do_something(std::make_pair("42", 42)));
  ASSERT_EQ("1337", do_something(1337));
}

TEST(DeducedReturnType, FromLambda)
{
  CallableMock mock;
  InSequence seq;
  auto wrapped = wrap(ref(mock), [&]{ mock.before(); }, [&]{ mock.after(); });

  EXPECT_CALL(mock, before());
  EXPECT_CALL(mock, call());
  EXPECT_CALL(mock, after());
  wrapped();
}
