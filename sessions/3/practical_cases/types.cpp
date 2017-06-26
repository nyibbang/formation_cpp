#include "types.hpp"

std::ostream& operator<<(std::ostream& os, Player player) {
    switch (player) {
    case Player::None:
        os << "Player::None";
        break;
    case Player::Orange:
        os << "Player::Orange";
        break;
    case Player::Red:
        os << "Player::Red";
        break;
    default:
        os << "<Player error>";
        break;
    }
    return os;
}

Row_range::Row_range(Board& board, int row) : _board(&board), _row(row) {
}

Row_range::Row_range(Row_range&& o) : _board(std::move(o._board)), _row(std::move(o._row)) {
}

Row_range& Row_range::operator=(Row_range&& o) {
    _board = std::move(o._board);
    _row = std::move(o._row);
    return *this;
}

Row_range::const_iterator Row_range::begin() const {
    const auto incr = (_row * Board::column_count::value);
    const auto board_begin = _board->value.cbegin();
    const auto board_end = _board->value.cend();
    if (board_end - board_begin < incr) {
        return board_end;
    }
    return _board->value.cbegin() + incr;
}

Row_range::iterator Row_range::begin() {
    const auto incr = (_row * Board::column_count::value);
    const auto board_begin = _board->value.begin();
    const auto board_end = _board->value.end();
    if (board_end - board_begin < incr) {
        return board_end;
    }
    return _board->value.begin() + incr;
}

Row_range::const_iterator Row_range::end() const {
    const auto incr = ((_row + 1) * Board::column_count::value);
    const auto board_begin = _board->value.cbegin();
    const auto board_end = _board->value.cend();
    if (board_end - board_begin < incr) {
        return board_end;
    }
    return _board->value.cbegin() + incr;
}

Row_range::iterator Row_range::end() {
    const auto incr = ((_row + 1) * Board::column_count::value);
    const auto board_begin = _board->value.begin();
    const auto board_end = _board->value.end();
    if (board_end - board_begin < incr) {
        return board_end;
    }
    return _board->value.begin() + incr;
}

std::size_t Row_range::size() const {
    return static_cast<std::size_t>(end() - begin());
}

bool Row_range::operator==(const Row_range& o) const {
    return std::tie(_board, _row) == std::tie(o._board, o._row);
}
