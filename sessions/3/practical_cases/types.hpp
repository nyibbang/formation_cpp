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
std::ostream& operator<<(std::ostream& os, const Board& board);

struct Slot {
    Slot() : row(-1), column(-1) {
    }

    Slot(int row, int column) : row(row), column(column) {
    }

    template <typename IterB, typename Iter>
    Slot(IterB b, Iter i)
        : row((i - b) / Board::column_count::value), column((i - b) % Board::column_count::value) {
    }

    bool operator==(const Slot& o) const {
        return std::tie(row, column) == std::tie(o.row, o.column);
    }

    int row;
    int column;
};
