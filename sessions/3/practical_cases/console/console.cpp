#include "logic.hpp"
#include "types.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main(int, char**) {
    try {
        Board board;
        Player current_player = Player::Red; //  starts with red

        Player winner_player = Player::None;
        while ((winner_player = winner(board)) == Player::None) {
            std::cout << board << "It is player " << current_player << "'s turn !";

            std::string input;
            int choice;
            do {
                std::cout << "Please choose a column to play at: ";
                std::getline(std::cin, input);
                std::stringstream ss(input);
                ss >> choice;
            } while (choice <= 0 || choice > Board::column_count::value);

            play_turn(board, current_player, choice);
            switch_player(current_player);
        }

        std::cout << "Winner is player " << winner_player << std::endl;
    } catch (const std::exception& ex) { std::cerr << "Fatal error: " << ex.what() << std::endl; }

    return 0;
}
