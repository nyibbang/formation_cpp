#include "types.hpp"
#include "ranges.hpp"
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
    const Row_range<Board> range{board, 1};
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
    const Column_range<Board> range{board, 1};
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
    const LeftDiagonal_range<Board> range{board, Slot{2, 2}};
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
    const RightDiagonal_range<Board> range{board, Slot{3, 3}};
    EXPECT_EQ(3u, range.size());
    auto iter = range.begin();
    EXPECT_EQ(Player::Red, *iter++);
    EXPECT_EQ(Player::Orange, *iter++);
}

// ******************************************************************************
// LOGIC
// ******************************************************************************
TEST(TestRun, Run) {
}

TEST(TestSwitchPlayer, SwitchPlayer) {
}

TEST(TestWinner, Winner) {
}

TEST(TestPlayTurn, PlayTurn) {
}
