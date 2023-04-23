//function file for tic tac toe game 3x3 board
//contributors: anthony
//progress: active devlopment

#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"

using std::string;
using std::vector;

TicTacToe3::TicTacToe3(vector<string> p, string winner) : TicTacToe(p, winner) {}

//checks if any player has won in any of the collums
bool TicTacToe3::check_column_win() {
  for (int i = 0; i < 3; i++) {
    if (pegs[i] == pegs[i+3] && pegs[i] == pegs[i+6] && pegs[i] != " ") {
      set_winner();
      return true;
    }
  }
  return false;
}

//checks if any player has won in any of the rows
bool TicTacToe3::check_row_win() {
  for (int i = 0; i < 9; i+=3) {
    if (pegs[i] == pegs[i+1] && pegs[i] == pegs[i+2] && pegs[i] != " ") {
      set_winner();
      return true;
    }
  }
  return false;
}

//checks if any player has won in either of the diagonals
bool TicTacToe3::check_diagonal_win() {
  if (pegs[1-1] == pegs[5-1] && pegs[1-1] == pegs[9-1] && pegs[1-1] != " ") {
    set_winner();
    return true;
  } else if (pegs[3-1] == pegs[5-1] && pegs[3-1] == pegs[7-1] && pegs[3-1] != " ") {
    set_winner();
    return true;
  }
  return false;
}
