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

// *************************************************************
// TODO
// *************************************************************
Player winner(const Board& board) {
    throw std::exception();
}

Board& play_turn(Board& board, Player player, int column) {
    const auto slot = playable_column_slot(board, column);
    if (slot.row != -1 && slot.column != -1) {
        const auto index = slot.row * Board::column_count::value + slot.column;
        board.value[index] = player;
    }
}

int getColumnChoice() {
    std::string input;
    int choice;
    do {
        std::cout << "Please choose a column to play at: ";
        std::getline(std::cin, input);
        std::stringstream ss(input);
        ss >> choice;
    } while (choice <= 0 || choice > Board::column_count::value);
}
