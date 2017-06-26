#pragma once

#include <array>

enum class Player : char {
    None = 0,
    Orange,
    Red,
};
std::ostream& operator<<(std::ostream& os, Player player);

//  0   1   2   3   4   5   6
//  7   8   9   10  11  12  13
//  14  15  16  17  18  19  20
//  21  22  23  24  25  26  27
//  28  29  30  31  32  33  34
//  35  36  37  38  39  40  41
struct Board {
    using row_count = std::integral_constant<int, 6>;
    using column_count = std::integral_constant<int, 7>;
    using value_type = std::array<Player, row_count::value * column_count::value>;
    value_type value;

    bool operator==(const Board& o) const {
        return value == o.value;
    }
};

struct Slot {
    int row;
    int column;
};

template <typename RAIter,
    std::size_t Stride,
    typename Enable = typename std::enable_if<
        std::is_same<std::random_access_iterator_tag,
            typename std::iterator_traits<RAIter>::iterator_category>::value,
        void>::type>
class Strided_iterator {
public:
    using self_type = Strided_iterator;
    using value_type = typename RAIter::value_type;
    using reference = typename RAIter::reference;
    using pointer = typename RAIter::pointer;
    using iterator_category = typename std::random_access_iterator_tag;
    using difference_type = typename RAIter::difference_type;

    Strided_iterator() : _iter(), _end() {
    }

    Strided_iterator(RAIter iter, RAIter end) : _iter(iter), _end(end) {
    }

    Strided_iterator(const Strided_iterator&) = default;
    Strided_iterator& operator=(const Strided_iterator&) = default;

    Strided_iterator(Strided_iterator&& o) : _iter(std::move(o._iter)), _end(std::move(o._end)) {
    }

    Strided_iterator& operator=(Strided_iterator&&) {
        _iter = std::move(o._iter);
        _end = std::move(o._end);
    }

    self_type& operator++() {
        if (std::distance(_iter, _end) <= Stride) {
            _iter = _end;
        } else {
            _iter += Stride;
        }
        return *this;
    }

    self_type operator++(int) {
        const auto tmp = *this;
        ++*this;
        return tmp;
    }

    self_type& operator+=(difference_type d) {
        const auto incr = Stride * d;
        if (std::distance(_iter, _end) <= incr) {
            _iter = _end;
        } else {
            _iter += incr;
        }
        return *this;
    }

    self_type& operator--() {
        _iter -= Stride;
        return *this;
    }

    self_type operator--(int) {
        const auto tmp = *this;
        --*this;
        return tmp;
    }

    self_type& operator-=(difference_type d) {
        const auto decr = Stride * d;
        _iter -= decr;
        return *this;
    }

    reference operator*() const {
        return *_iter;
    }

    pointer operator->() const {
        return &*_iter;
    }

    friend self_type operator+(const self_type& i, difference_type d) {
        auto tmp = i;
        return (tmp += d);
    }

    friend self_type operator+(difference_type d, const self_type& i) {
        auto tmp = i;
        return (tmp += d);
    }

    friend self_type operator-(const self_type& i, difference_type d) {
        auto tmp = i;
        return (tmp -= d);
    }

    friend self_type operator-(difference_type d, const self_type& i) {
        auto tmp = i;
        return (tmp -= d);
    }

    friend void swap(self_type& lhs, self_type& rhs) {
        using std::swap;
        swap(lhs._iter, rhs._iter);
        swap(lhs._end, rhs._end);
    }

    template <typename ItL, typename ItR, std::size_t S>
    friend typename Strided_iterator<ItL, S>::difference_type operator-(
        const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator<(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator>(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator<=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator>=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator==(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator!=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

private:
    std::tuple<RAIter, RAIter> tie() const {
        return std::tie(_iter, _end);
    }

    RAIter _iter;
    RAIter _end;
};

template <typename ItL, typename ItR, std::size_t S>
typename Strided_iterator<ItL, S>::difference_type operator-(
    const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    const auto diff = (l._iter - r._iter);
    return (diff / static_cast<typename Strided_iterator<ItL, S>::difference_type>(S)) + 1;
}

template <typename ItL, typename ItR, std::size_t S>
bool operator<(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() < r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator>(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() > r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator<=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() <= r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator>=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() >= r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator==(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() == r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator!=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() != r.tie();
}

template <std::size_t Incr>
class Board_strided_range {
public:
    using iterator = Strided_iterator<Board::value_type::iterator, Incr>;
    using const_iterator = Strided_iterator<Board::value_type::const_iterator, Incr>;

    Board_strided_range(Board& board, Slot slot) : _board(&board), _slot(slot) {
    }

    Board_strided_range(const Board_strided_range&) = default;
    Board_strided_range& operator=(const Board_strided_range&) = default;

    Board_strided_range(Board_strided_range&& o) : _board(std::move(o._board)), _slot(std::move(o._slot)) {
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

private:
    Board* _board;
    Slot _slot;
};

class Column_range : public Board_strided_range<Board::column_count::value> {
public:
    Column_range(Board& board, int column) : Board_strided_range(board, Slot{0, column}) {
    }
};
using LeftDiagonal_range = Board_strided_range<Board::column_count::value - 1>;
using RightDiagonal_range = Board_strided_range<Board::column_count::value + 1>;

class Row_range {
public:
    using iterator = Board::value_type::iterator;
    using const_iterator = Board::value_type::const_iterator;

    Row_range(Board& board, int row);
    Row_range(const Row_range&) = default;
    Row_range& operator=(const Row_range&) = default;
    Row_range(Row_range&& o);
    Row_range& operator=(Row_range&& o);

    const_iterator begin() const;
    iterator begin();
    const_iterator end() const;
    iterator end();
    std::size_t size() const;

    bool operator==(const Row_range& o) const;

private:
    Board* _board;
    int _row;
};
