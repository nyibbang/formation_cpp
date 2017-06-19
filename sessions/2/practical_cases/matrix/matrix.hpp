#pragma once

#include <string>
#include <vector>

namespace matrix
{
  
class Matrix
{
public:
  explicit Matrix(int size);

  int size() const;
  double element(int row, int col) const;
  void setElement(int row, int col, double value);

private:
  int _size;
  std::vector<double> _values;
};

//////////////////////////////////////////////////////////////////////////
/// A implémenter
//////////////////////////////////////////////////////////////////////////
Matrix multiply(const Matrix& mat1, const Matrix& mat2);


}
