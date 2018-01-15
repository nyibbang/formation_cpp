#include "types.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& os, Player player) {
    switch (player) {
    case Player::None:
        os << "None";
        break;
    case Player::Orange:
        os << "Orange";
        break;
    case Player::Red:
        os << "Red";
        break;
    default:
        os << "<Player error>";
        break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    os << "+--------------------+";
    for (std::size_t i = 0u; i < board.value.size(); ++i) {
        if (i % Board::column_count::value == 0) {
            os << "\n| ";
        }
        switch (board.value[i]) {
        case Player::None:
            os << " ";
            break;
        case Player::Orange:
            os << "O";
            break;
        case Player::Red:
            os << "R";
            break;
        }
        os << " | ";
    }
    os << "\n+--------------------+\n";
    return os;
}
