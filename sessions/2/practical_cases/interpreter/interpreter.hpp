#pragma once

#include <string>
#include <tuple>

namespace intpt
{
  
//////////////////////////////////////////////////////////////////////////
/// Types
//////////////////////////////////////////////////////////////////////////
enum class Action
{
  Eat,
  Pray,
  Love,
};
  
class AbstractParser
{
public:
  AbstractParser() = default;
  virtual ~AbstractParser() = default;

  // Découpe une expression sous la forme "<eat|pray|love>: <count> <text>"
  // et retourne l'action, le count et le text sous forme d'une tuple
  virtual std::tuple<Action, int, std::string>  parse(const std::string& expr) const = 0;
};

class AbstractActor
{
public:
  AbstractActor() = default;
  virtual ~AbstractActor() = default;
  
  virtual void eat(int count, const std::string& text) = 0;
  virtual void pray(int count, const std::string& text) = 0;
  virtual void love(int count, const std::string& text) = 0;
};

class Interpreter
{
public:
  Interpreter(const AbstractParser& parser, AbstractActor& actor);

  //////////////////////////////////////////////////////////////////////////
  /// A implémenter
  /// Parse le text grâce au Parser et selon le résultat, agit sur l'Actor
  //////////////////////////////////////////////////////////////////////////
  void interpret(const std::string& text);

private:
  const AbstractParser& _parser;
  AbstractActor& _actor;
};

}
