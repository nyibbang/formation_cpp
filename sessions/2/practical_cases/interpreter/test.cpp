#include "interpreter.hpp"
#include <gmock/gmock.h>

namespace
{

class MockParser : public intpt::AbstractParser
{
public:
  MOCK_CONST_METHOD1(parse, std::tuple<intpt::Action, int, std::string>(const std::string&));
};

class MockActor : public intpt::AbstractActor
{
public:  
  MOCK_METHOD2(eat, void(int, const std::string&));
  MOCK_METHOD2(pray, void(int, const std::string&));
  MOCK_METHOD2(love, void(int, const std::string&));
};

}

//////////////////////////////////////////////////////////////////////////
/// A implémenter
//////////////////////////////////////////////////////////////////////////
TEST(Interpreter, FirstTestCase) // TODO change test case name
{
  // TODO
}
