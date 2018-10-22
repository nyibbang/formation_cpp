#include <iostream>
#include <sstream>
#include <cassert>

std::string print(int p)
{
  std::ostringstream oss;
  oss << "int: " << p;
  return oss.str();
}

std::string print(double p)
{
  std::ostringstream oss;
  oss << "double: " << p;
  return oss.str();
}

std::string print(const char* p)
{
  assert(p != nullptr);
  std::ostringstream oss;
  oss << "string: " << p;
  return oss.str();
}

// TODO:
// Surcharger print pour lorsqu'elle est appelée de la façon suivante: print(nullptr)
