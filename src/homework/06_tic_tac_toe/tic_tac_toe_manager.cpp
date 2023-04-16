//function file for tic tac toe manager class
//contributors: anthony
//progress: active devlopment

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"


//TicTacToeManager Class functions: ---------------------------------------------------------------------

//public of the TicTacToeManager class: -----------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) {
  for (const auto& game : manager.games) {out << *game << endl;}

  out << "X wins: " << manager.x_win << "\n";
  out << "O Wins: " << manager.o_win << "\n";
  out << "Ties: " << manager.ties << "\n";
  return out;
}

//calls other functions to save the game board and update win count
void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& b) {
  update_winner_count(b->get_winner());
  games.push_back(std::move(b));
}

//displays the win count
void TicTacToeManager::get_winner_total(int& o, int& w, int& t) {
  o = o_win;
  w = x_win;
  t = ties;
  cout << "X wins: " << w << "\nO wins: " << o << "\nTies: " << t << endl;
}

//private of the TicTacToeManager class: ----------------------------------------------------------------

//updates the win count
void TicTacToeManager::update_winner_count(string winner) {
       if (winner == "X"){x_win++;}
  else if (winner == "O"){o_win++;}
  else if (winner == "C"){ties++;}
}
