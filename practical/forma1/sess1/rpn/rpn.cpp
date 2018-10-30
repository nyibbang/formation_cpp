#include "rpn.hpp"
#include <stdexcept>
#include <cstdint>

namespace rpn
{

//////////////////////////////////////////////////////////////////////////
/// A implémenter
//////////////////////////////////////////////////////////////////////////
int interpret(const std::string expr)
{
  // TODO
  throw std::runtime_error("not yet implemented !");
}


//////////////////////////////////////////////////////////////////////////
/// Detail: fonctions utilitaires
//////////////////////////////////////////////////////////////////////////
namespace detail
{

namespace
{

class SubStringsIterator
{
public:
  using It = std::string::const_iterator;
  using value_type = std::string;
  using difference_type = std::ptrdiff_t;
  using pointer = std::string*;
  using reference = std::string&;
  using iterator_category = std::forward_iterator_tag;

  SubStringsIterator(const std::string& str)
    : SubStringsIterator(str.begin(), str.end())
  {}

  SubStringsIterator(It begin, It end)
    : _current(begin)
    , _end(end)
    , _defaulted(false)
  {
  }

  SubStringsIterator()
    : _defaulted(true)
  {
  }

  SubStringsIterator& operator++()
  {
    while (_current != _end && *_current != ' ')
      ++_current;
    while (_current != _end && *_current == ' ')
      ++_current;
    return *this;
  }

  std::string operator*() const
  {
    auto endPoint = _current;
    while (endPoint != _end && *endPoint != ' ')
      ++endPoint;
    return std::string(_current, endPoint);
  }

  bool operator==(const SubStringsIterator& o) const
  {
    if (o._defaulted)
      return _current == _end;
    if (_defaulted)
      return o._current == o._end;
    return _current == o._current && _end == o._end;
  }

  bool operator!=(const SubStringsIterator& o) const
  {
    return !(*this == o);
  }

private:
  It _current;
  It _end;
  bool _defaulted;
};

}

std::vector<std::string> split(std::string expr)
{
  std::vector<std::string> res;
  std::copy(SubStringsIterator(expr), SubStringsIterator{},
            std::back_inserter(res));
  return res;
}

}

}
