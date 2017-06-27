#pragma once

#include "types.hpp"
#include <memory>

Slot playable_column_slot(const Board& board, int column);

// *************************************************************
// TODO
// *************************************************************
Player& switch_player(Player& player);
Player winner(const Board& board);
Board& play_turn(Board& board, Player player, int column);

// Winner, PlayTurn et SwitchPlayer sont des functors
template <typename Winner, typename PlayTurn, typename SwitchPlayer>
void run(Winner winner, PlayTurn playTurn, SwitchPlayer switchPlayer) {
  throw std::exception();
}
