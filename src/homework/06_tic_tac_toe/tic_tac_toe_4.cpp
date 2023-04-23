//function file for tic tac toe game 4x4 board
//contributors: anthony
//progress: active devlopment

#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_4.h"

using std::string;
using std::vector;

TicTacToe4::TicTacToe4(vector<string> p, string winner) : TicTacToe(p, winner) {}

//checks if any player has won in any of the collums
bool TicTacToe4::check_column_win() {
  for (int i = 0; i < 4; i++) {
    if (pegs[i] == pegs[i+4] && pegs[i] == pegs[i+8] && pegs[i] == pegs[i+12] && pegs[i] != " ") {
      set_winner();
      return true;
    }
  }
  return false;
}

//checks if any player has won in any of the rows
bool TicTacToe4::check_row_win() {
  for (int i = 0; i < 16; i+=4) {
    if (pegs[i] == pegs[i+1] && pegs[i] == pegs[i+2] && pegs[i] == pegs[i+3] && pegs[i] != " ") {
      set_winner();
      return true;
    }
  }
  return false;
}

//checks if any player has won in either of the diagonals
bool TicTacToe4::check_diagonal_win() {
  if (pegs[1-1] == pegs[6-1] && pegs[1-1] == pegs[11-1] && pegs[1-1] == pegs[16-1] && pegs[1-1] != " ") {
    set_winner();
    return true;
  } else if (pegs[4-1] == pegs[7-1] && pegs[4-1] == pegs[10-1] && pegs[4-1] == pegs[13-1] && pegs[4-1] != " ") {
    set_winner();
    return true;
  }
  return false;
}

