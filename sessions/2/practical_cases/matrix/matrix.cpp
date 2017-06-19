#include "matrix.hpp"
#include <stdexcept>
#include <tuple>

namespace matrix
{

Matrix::Matrix(int size)
  : _size(size)
{
  _values.resize(_size * size, std::nan(""));
}

bool operator==(const Matrix& l, const Matrix& r)
{
  return std::tie(l._values, l._size) == std::tie(r._values, r._size);
}

int Matrix::size() const
{
  return _size;
}

double Matrix::element(int row, int col) const
{
  return _values.at(row * _size + col);
}

void Matrix::setElement(int row, int col, double value)
{
  _values.at(row * _size + col) = value;
}

//////////////////////////////////////////////////////////////////////////
/// A implémenter
//////////////////////////////////////////////////////////////////////////
Matrix multiply(const Matrix& mat1, const Matrix& mat2)
{
  // TODO
  throw std::runtime_error("not yet implemented !");
}

}
