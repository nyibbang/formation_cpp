#pragma once

#include "types.hpp"
#include <memory>

Player& switch_player(Player& player);
Slot playable_column_slot(const Board& board, int column);

// *************************************************************
// TODO
// *************************************************************
Player winner(const Board& board);
Board& play_turn(Board& board, Player player, int column);
