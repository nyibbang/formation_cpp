#include "matrix.hpp"
#include <stdexcept>

namespace matrix
{

Matrix::Matrix(int size)
  : _size(size)
{
  _values.resize(_size * size, std::nan(""));
}

int Matrix::size() const
{
  return _size;
}

double Matrix::element(int row, int col) const
{
  return _values[row * _size + col];
}

void Matrix::setElement(int row, int col, double value)
{
  _values[row * _size + col] = value;
}

//////////////////////////////////////////////////////////////////////////
/// A implémenter
//////////////////////////////////////////////////////////////////////////
Matrix multiply(const Matrix& mat1, const Matrix& mat2);
{
  // TODO
  throw std::runtime_error("not yet implemented !");
}

}
