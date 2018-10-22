#include <iostream>
#include <array>
#include <numeric>

// Un tableau qui contient des valeurs qui croissent:
//   [1, 2, 3, 4, 5, 6, ...]
class CountingArray
{
public:
  using Data = std::array<int, 64>;
  using Iterator = Data::iterator;

  CountingArray()
  {
    std::iota(_data.begin(), _data.end(), 1);
  }

  // TODO:
  // Implémenter les méthodes pour que CountingArray puisse être utiliser dans
  // une boucle range-for.
  //

private:
  Data _data;
};
