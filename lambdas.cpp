#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

namespace
{

template<typename Proc, typename ProcBefore, typename ProcAfter>
auto wrap(Proc p, ProcBefore before, ProcAfter after) {
  return [=](auto&&... args) mutable {
    before();
    const auto r = p(std::forward<decltype(args)>(args)...);
    after();
    return r;
  };
}

struct CallableMock
{
  MOCK_METHOD0(before, void());
  MOCK_METHOD1(call, bool(int));
  MOCK_METHOD0(after, void());

  template<typename... Args>
  auto operator()(Args&&... args) {
    return call(std::forward<Args>(args)...);
  }
};

}

TEST(Lambda, Generic)
{
  auto multiply = [](auto a, auto b) { return a * b; };
  ASSERT_EQ(12, multiply(3, 4));
  ASSERT_DOUBLE_EQ(7.5, multiply(2.5, 3));
}
TEST(Lambdas, GenericVariadic)
{
  CallableMock mock;
  InSequence seq;
  auto wrapped = wrap(ref(mock), [&]{ mock.before(); }, [&]{ mock.after(); });

  EXPECT_CALL(mock, before());
  EXPECT_CALL(mock, call(42)).WillOnce(Return(false));
  EXPECT_CALL(mock, after());
  ASSERT_FALSE(wrapped(42));
}

TEST(Lambdas, ExtendedCapture)
{
  auto answer_to_life = [x = 42]{ return x; };
  ASSERT_EQ(42, answer_to_life());
}

TEST(Lambdas, MoveOnlyCapture)
{
  unique_ptr<int> ptr{new auto(42)};
  auto capture_moveonly = [ptr = move(ptr)] {
      return *ptr;
  };
  ASSERT_EQ(42, capture_moveonly());
  ASSERT_FALSE(ptr);
}

