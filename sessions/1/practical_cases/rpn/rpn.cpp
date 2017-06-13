#include "rpn.hpp"
#include <stdexcept>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>

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

std::vector<std::string> split(std::string expr)
{
  if (expr.empty())
  {
    return {};
  }

  std::vector<std::string> res;
  boost::algorithm::trim(expr);
  boost::algorithm::split(res, expr, [](char c) { return c == ' '; }, boost::algorithm::token_compress_on);
  return res;
}

}

}
