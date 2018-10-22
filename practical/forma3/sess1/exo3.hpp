#include <string>

// TODO:
// Remplacer un maximum de type par auto.
//
// Note: ce code n'a aucun sens.

float get_factor()
{
  return 3.14;
}

void multiply_by_five(int& v)
{
  int five = 5.;
  v *= five;
}

std::string calculus_as_string()
{
  int v = 1;
  for (int i = 0; i < 10; ++i)
    v *= 2;
  int r = v * get_factor();
  multiply_by_five(r);
  std::string result = std::to_string(r);
  std::string suffix = "_the_end_!";
  result += suffix;
  return result;
}
