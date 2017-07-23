#pragma once

#include "types.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <memory>

Slot playable_column_slot(const Board& board, int column);
Player& switch_player(Player& player);
int getColumnChoice();

// *************************************************************
// TODO
// *************************************************************
Player winner(const Board& board);
Board& play_turn(Board& board, Player player, int column);

// Winner, PlayTurn et SwitchPlayer sont des functors
template <typename Winner, typename PlayTurn, typename SwitchPlayer, typename GetColumnChoice>
void run(Winner winner, PlayTurn playTurn, SwitchPlayer switchPlayer, GetColumnChoice getChoice) {
  Board board;
  auto current_player = Player::Red; //  starts with red

  auto winner_player = Player::None;
  while ((winner_player = winner(board)) == Player::None) {
      std::cout << board << "It is player " << current_player << "'s turn !\n";
      const auto choice = getChoice();
      playTurn(board, current_player, choice);
      switchPlayer(current_player);
  }

  std::cout << "Winner is player " << winner_player << std::endl;
}
