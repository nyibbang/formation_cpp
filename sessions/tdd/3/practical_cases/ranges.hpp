#pragma once

#include "strided_iterator.hpp"
#include "types.hpp"

template <std::size_t Incr, typename Board>
class Board_strided_range {
public:
    using iterator = Strided_iterator<typename Board::value_type::iterator, Incr>;
    using const_iterator = Strided_iterator<typename Board::value_type::const_iterator, Incr>;

    Board_strided_range(Board& board, Slot slot) : _board(&board), _slot(slot) {
    }

    Board_strided_range(const Board_strided_range&) = default;
    Board_strided_range& operator=(const Board_strided_range&) = default;

    Board_strided_range(Board_strided_range&& o)
        : _board(std::move(o._board)), _slot(std::move(o._slot)) {
    }

    Board_strided_range& operator=(Board_strided_range&& o) {
        _board = std::move(o._board);
        _slot = std::move(o._slot);
        return *this;
    }

    const_iterator begin() const {
        const auto incr = (_slot.row * Board::column_count::value) + _slot.column;
        const auto board_begin = _board->value.cbegin();
        const auto board_end = _board->value.cend();
        if (board_end - board_begin < incr) {
            return {board_end, board_end};
        }
        return {board_begin + incr, board_end};
    }

    iterator begin() {
        const auto incr = (_slot.row * Board::column_count::value) + _slot.column;
        const auto board_begin = _board->value.begin();
        const auto board_end = _board->value.end();
        if (board_end - board_begin < incr) {
            return {board_end, board_end};
        }
        return {board_begin + incr, board_end};
    }

    const_iterator end() const {
        const auto board_end = _board->value.end();
        return {board_end, board_end};
    }

    iterator end() {
        const auto board_end = _board->value.end();
        return {board_end, board_end};
    }

    std::size_t size() const {
        return static_cast<std::size_t>(end() - begin());
    }

    bool operator==(const Board_strided_range& o) const {
        return std::tie(_board, _slot) == std::tie(o._board, o._slot);
    }

private:
    Board* _board;
    Slot _slot;
};

template <typename B>
class Column_range : public Board_strided_range<Board::column_count::value, B> {
public:
    Column_range(B& board, int column) : Board_strided_range<Board::column_count::value, B>(board, Slot{0, column}) {
    }
};

template <typename B>
using LeftDiagonal_range = Board_strided_range<Board::column_count::value - 1, B>;

template <typename B>
using RightDiagonal_range = Board_strided_range<Board::column_count::value + 1, B>;

template <typename B>
class Row_range {
public:
    using iterator = typename B::value_type::iterator;
    using const_iterator = typename B::value_type::const_iterator;

    Row_range(B& board, int row) : _board(&board), _row(row) {
    }

    Row_range(const Row_range&) = default;
    Row_range& operator=(const Row_range&) = default;

    Row_range(Row_range&& o) : _board(std::move(o._board)), _row(std::move(o._row)) {
    }

    Row_range& operator=(Row_range&& o) {
        _board = std::move(o._board);
        _row = std::move(o._row);
        return *this;
    }

    const_iterator begin() const {
        const auto incr = (_row * Board::column_count::value);
        const auto board_begin = _board->value.cbegin();
        const auto board_end = _board->value.cend();
        if (board_end - board_begin < incr) {
            return board_end;
        }
        return _board->value.cbegin() + incr;
    }

    iterator begin() {
        const auto incr = (_row * Board::column_count::value);
        const auto board_begin = _board->value.begin();
        const auto board_end = _board->value.end();
        if (board_end - board_begin < incr) {
            return board_end;
        }
        return _board->value.begin() + incr;
    }

    const_iterator end() const {
        const auto incr = ((_row + 1) * Board::column_count::value);
        const auto board_begin = _board->value.cbegin();
        const auto board_end = _board->value.cend();
        if (board_end - board_begin < incr) {
            return board_end;
        }
        return _board->value.cbegin() + incr;
    }

    iterator end() {
        const auto incr = ((_row + 1) * Board::column_count::value);
        const auto board_begin = _board->value.begin();
        const auto board_end = _board->value.end();
        if (board_end - board_begin < incr) {
            return board_end;
        }
        return _board->value.begin() + incr;
    }

    std::size_t size() const {
        return static_cast<std::size_t>(end() - begin());
    }

    bool operator==(const Row_range& o) const {
        return std::tie(_board, _row) == std::tie(o._board, o._row);
    }

private:
    B* _board;
    int _row;
};
