#include "interpreter.hpp"
#include <stdexcept>

namespace intpt
{

Interpreter::Interpreter(const AbstractParser& parser, AbstractActor& actor)
  : _parser(parser)
  , _actor(actor)
{
}

//////////////////////////////////////////////////////////////////////////
/// A implémenter
/// Parse le text grâce au Parser et selon le résultat, agit sur l'Actor
//////////////////////////////////////////////////////////////////////////
void Interpreter::interpret(const std::string& text)
{
  // TODO
  throw std::runtime_error("not yet implemented !");
}

}
