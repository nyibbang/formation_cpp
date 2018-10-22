#include <algorithm>
#include <string>
#include <vector>

struct Complex_type
{
  std::string str;
  int i;
};

// On veut se passer de ces deux types
struct Equals_by_string
{
  std::string str;
  bool operator()(const Complex_type& t) const
  {
    return t.str == str;
  }
};

struct Equals_by_int
{
  int v;
  bool operator()(const Complex_type& t) const
  {
    return t.i == v;
  }
};

using Complex_type_vector = std::vector<Complex_type>;

// TODO: Implémenter ces fonctions en remplaçant le dernier argument de
// std::find_if par une lambda.

Complex_type_vector::const_iterator
  find_by_string(const Complex_type_vector& vec, const std::string& str)
{
  return std::find_if(vec.begin(), vec.end(), Equals_by_string{str});
}

Complex_type_vector::const_iterator
  find_by_int(const Complex_type_vector& vec, int v)
{
  return std::find_if(vec.begin(), vec.end(), Equals_by_int{v});
}
