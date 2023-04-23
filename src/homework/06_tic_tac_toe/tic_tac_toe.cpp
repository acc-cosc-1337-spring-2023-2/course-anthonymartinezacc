//function file for tic tac toe game program that contains all the functions the program needs to call to
//contributors: anthony
//progress: active devlopment

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//TicTacToe Class functions: ---------------------------------------------------------------------


//public of the TicTacToe class: -----------------------------------------------------------------
/*
//constuctor for TicTacToe class
TicTacToe::TicTacToe() {
    player = "";
    winner = "";
    pegs = {9, " "};
}*/

TicTacToe::TicTacToe(vector<string> p, string win) : pegs{p}, winner{win} {}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
  int size = std::sqrt(game.pegs.size());
  for (int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
          cout << game.pegs.at(i * size + j);
          if (j < size-1) { cout << " | "; }
      }
      cout << endl;

      //if (i < size-1) {cout << "---------" << endl;}
      if (i < size - 1) {
          for (int k = 0; k < size; k++) {
                out << "---";}
          out << "\n";}
  }
  out << endl;
  return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game) {
  int position;
  bool valid_position = false;
  while (valid_position == false) {
      cout << "Enter position from 1 to " << game.pegs.size() << ": ";
      cin >> position;
      if (position > 0 && position <= game.pegs.size()) {
          valid_position = true;
          break;
      }
      else {
          cout << "\nInvalid Position. Please select a position of 1 through " << game.pegs.size() << endl;
      }
  }
  game.mark_board(position);
  return in;
}

vector<string> TicTacToe::get_pegs() const
{
    return pegs;
}

//checks if the game is over, (by both win and tie)
bool TicTacToe::game_over() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }
    else if (check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

//sets the player variable, and calls the clear board function
void TicTacToe::start_game(string first_player) {
  player = first_player;
  clear_board();
}

//uses the user input to mark a board position
void TicTacToe::mark_board(int position) {
  pegs[position-1] = player;
  set_next_player();
}

//returns current player
string TicTacToe::get_player() const {
    return player;
}

//retruns player that won the game (returns C if tie)
string TicTacToe::get_winner() const {
    return winner;
}

/*
//displays the current tic tac toe board
void TicTacToe::display_board() const {
    //the -1 is to have parity with the board position numbers (0 index vs 1 index stuff)
    cout << " " << pegs[1-1] << " | " << pegs[2-1] << " | " << pegs[3-1] << " \n"
         << "-----------\n"
         << " " << pegs[4-1] << " | " << pegs[5-1] << " | " << pegs[6-1] << " \n"
         << "-----------\n"
         << " " << pegs[7-1] << " | " << pegs[8-1] << " | " << pegs[9-1] << " " << endl;

    //this code can also alternativly be writen as a loop
    //for (int i = 0; i < 9; i++) {
    //    if (i % 3 == 0 && i != 0) {
    //        cout << "\n---------\n";
    //    }
    //    cout << pegs[i];
    //    if (i % 3 != 2) {
    //        cout << " | ";
    //    }
    //}
    //cout << endl;

} */

//protected of the TicTacToe class: ----------------------------------------------------------------

//checks if any player has won in any of the collums
bool TicTacToe::check_column_win() {
  for (int i = 0; i < 3; i++) {
    if (pegs[i] == pegs[i+3] && pegs[i] == pegs[i+6] && pegs[i] != " ") {
      set_winner();
      return true;
    }
  }
  return false;
}

//checks if any player has won in any of the rows
bool TicTacToe::check_row_win() {
  for (int i = 0; i < 9; i+=3) {
    if (pegs[i] == pegs[i+1] && pegs[i] == pegs[i+2] && pegs[i] != " ") {
      set_winner();
      return true;
    }
  }
  return false;
}

//checks if any player has won in either of the diagonals
bool TicTacToe::check_diagonal_win() {
  if (pegs[0] == pegs[4] && pegs[0] == pegs[8] && pegs[0] != " ") {
    set_winner();
    return true;
  } else if (pegs[2] == pegs[4] && pegs[2] == pegs[6] && pegs[2] != " ") {
    set_winner();
    return true;
  }
  return false;
}

//updates the winner variable with the winning player
void TicTacToe::set_winner() {
  if (player == "X") {
    winner = "O";
  } else {
    winner = "X";
  }
}

//private of the TicTacToe class: ----------------------------------------------------------------

//updates the player variable to the current player
//called at the end of a players turn
void TicTacToe::set_next_player() {
    if (player == "X") {player = "O";}
    else               {player = "X";}
}

//checks if the board is full or not
bool TicTacToe::check_board_full() {
  for (string peg : pegs) {
    if (peg == " ") {
      return false;
    }
  }
  return true;
}

//clears the board by setting all elements to the empty character ' '
void TicTacToe::clear_board() {
  for (int i = 0; i < 9; i++) {
       pegs[i] = " ";
  }
}
