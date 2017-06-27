#include "logic.hpp"
#include "ranges.hpp"
#include <stdexcept>

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
Player& switch_player(Player& player) {
    throw std::exception();
}

Player winner(const Board& board) {
    throw std::exception();
}

Board& play_turn(Board& board, Player player, int column) {
    throw std::exception();
}
