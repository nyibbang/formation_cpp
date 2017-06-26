#include "logic.hpp"
#include "ranges.hpp"
#include <stdexcept>

Player& switch_player(Player& player) {
    switch (player) {
    case Player::None:
    case Player::Orange:
        player = Player::Red;
        break;
    case Player::Red:
        player = Player::Orange;
        break;
    }
    return player;
}

Slot playable_column_slot(const Board& board, int column) {
    const Column_range<const Board> range{board, column};
    auto it = range.begin();
    while (it != range.end()) {
        if (*it != Player::None) {
            return {board.value.begin(), it};
        }
        ++it;
    }
    return {};
}

// *************************************************************
// TODO
// *************************************************************
Player winner(const Board& board) {
    throw std::exception();
}

Board& play_turn(Board& board, Player player, int column) {
    throw std::exception();
}
