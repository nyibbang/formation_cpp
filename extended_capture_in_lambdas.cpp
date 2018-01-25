#include <memory>
#include <gtest/gtest.h>

using namespace std;

void extended_capture_in_lambdas()
{
  // 1
  {
    auto answer_to_life = [x = 42]{ return x; };
  }

  // 2
  {
    unique_ptr<int> ptr{new auto(42)};
    auto capture_ownership = [ptr = move(ptr)] {
        return *ptr;
    };
    cout << capture_ownership() << std::endl;
    assert(ptr);
  }
}
