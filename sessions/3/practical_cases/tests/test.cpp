#include "types.hpp"
#include <gtest/gtest.h>

class TestBoard : public ::testing::Test {
protected:
    void SetUp() {
        board = Board{{{Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Orange,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red,
            Player::Red}}};
    }

    Board board;
};

TEST_F(TestBoard, RowRange) {
    const Row_range range{board, 1};
    EXPECT_EQ(7u, range.size());
    auto iter = range.begin();
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
}

TEST_F(TestBoard, ColumnRange) {
    const Column_range range{board, 1};
    EXPECT_EQ(6u, range.size());
    auto iter = range.begin();
    EXPECT_EQ(Player::Orange, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Orange, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Orange, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
}

TEST_F(TestBoard, LeftDiagonalRange) {
    const LeftDiagonal_range range{board, Slot{2, 2}};
    EXPECT_EQ(5u, range.size());
    auto iter = range.begin();
    EXPECT_EQ(Player::Orange, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Orange, *iter++);
    // circle back
    EXPECT_EQ(Player::Orange, *iter++);
    EXPECT_EQ(Player::Red, *iter++);
}

TEST_F(TestBoard, RightDiagonalRange) {
    const RightDiagonal_range range{board, Slot{3, 3}};
    EXPECT_EQ(3u, range.size());
    auto iter = range.begin();
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Orange, *iter++);
}
