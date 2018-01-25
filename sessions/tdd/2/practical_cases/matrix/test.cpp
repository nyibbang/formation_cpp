#include "matrix.hpp"
#include <gtest/gtest.h>

TEST(MatrixType, Size)
{
  matrix::Matrix mat(4);
  EXPECT_EQ(4, mat.size());
}

TEST(MatrixType, Element)
{
  matrix::Matrix mat(2);
  mat.setElement(0, 1, 3.14);
  EXPECT_DOUBLE_EQ(3.14, mat.element(0, 1));
}

TEST(MatrixType, BadElement)
{
  matrix::Matrix mat(2);
  EXPECT_THROW(mat.setElement(0, 5, 3.14), std::exception);
  EXPECT_THROW(mat.setElement(3, 1, 3.14), std::exception);
  EXPECT_THROW(mat.element(1, 4), std::exception);
  EXPECT_THROW(mat.element(2, 0), std::exception);
}

TEST(MatrixType, CopyEquality)
{
  matrix::Matrix mat(4);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      mat.setElement(i, j, static_cast<double>(i + 1 * j + 1));

  auto copy = mat;
  ASSERT_EQ(mat, copy);
}

//////////////////////////////////////////////////////////////////////////
/// A implémenter
//////////////////////////////////////////////////////////////////////////
TEST(Matrix, FirstTestCase) // TODO change test case name
{
  // TODO
}
