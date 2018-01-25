#include "types.hpp"
#include "ranges.hpp"
#include "logic.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockFunctions : public ::testing::Mock
{
public:
    MOCK_METHOD1(switch_player, Player&(Player&));
    MOCK_METHOD1(winner, Player(const Board&));
    MOCK_METHOD0(getColumnChoice, int());
    MOCK_METHOD3(play_turn, Board&(Board&, Player, int));
};


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

using namespace ::testing;

// ******************************************************************************
// LOGIC
// ******************************************************************************
TEST(TestRun, Run) {
    StrictMock<MockFunctions> func;

    Player player;
    Board board;

    InSequence s;
    EXPECT_CALL(func, winner(_)).WillOnce(Return(Player::None));
    EXPECT_CALL(func, getColumnChoice()).WillOnce(Return(42));
    EXPECT_CALL(func, play_turn(_, _, 42)).WillOnce(ReturnRef(board));
    EXPECT_CALL(func, switch_player(_)).WillOnce(DoAll(Assign(&player, Player::Red), ReturnRef(player)));
    EXPECT_CALL(func, winner(_)).WillOnce(Return(Player::None));
    EXPECT_CALL(func, getColumnChoice()).WillOnce(Return(42));
    EXPECT_CALL(func, play_turn(_, Player::Red, 42)).WillOnce(ReturnRef(board));
    EXPECT_CALL(func, switch_player(_)).WillOnce(DoAll(Assign(&player, Player::Red), ReturnRef(player)));
    EXPECT_CALL(func, winner(_)).WillOnce(Return(Player::Red));
    using namespace std::placeholders;
    run(std::bind(&MockFunctions::winner, &func, _1),
            std::bind(&MockFunctions::play_turn, &func, _1, _2, _3),
            std::bind(&MockFunctions::switch_player, &func, _1),
            std::bind(&MockFunctions::getColumnChoice, &func));
}

TEST(TestSwitchPlayer, SwitchPlayerOrange) {
    Player player = Player::Orange;
    switch_player(player);
    EXPECT_EQ(Player::Red, player);
}

TEST(TestSwitchPlayer, SwitchPlayerRed) {
    Player player = Player::Red;
    switch_player(player);
    EXPECT_EQ(Player::Orange, player);
}

TEST(TestSwitchPlayer, SwitchPlayerNone) {
    Player player = Player::None;
    switch_player(player);
    EXPECT_EQ(Player::Red, player);
}

TEST(TestWinner, Winner) {
}

TEST(TestPlayTurn, PlayTurn) {
    Board board {{{Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,

            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,

            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,

            Player::Red,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,

            Player::Orange,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,

            Player::Red,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None,
            Player::None}}};
    play_turn(board, Player::Red, 0);
    EXPECT_EQ(Player::Red, board.value[14]);
}
