//tic tac toe program that allows 2 players to play tic tac toe
//contributors: anthony
//progress: active devlopment

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "tic_tac_toe.cpp"
#include "tic_tac_toe.h"

using std::cout; using std::cin;
using std::endl;
using std::string;

int main() {
  TicTacToe game;           //Object from the TicTacToe Class
  string exitOption;        //var used to ask user if they would like to play again
  string first_player;      //var used to store if the first player would like to be a X or a O
  bool valid_input = false; //bool used to validate if the user put an X or O for first_player var
  int position;             //user input for board position | used on line 41

//do is for the code starting at line 60
do {
  //ask user for and X or O and validates their input
  while (!valid_input) {
    cout << "Enter first player (X or O): ";
    cin >> first_player;
    if (first_player == "x") {first_player = "X";}
    if (first_player == "o") {first_player = "O";}
    if (first_player == "0") {first_player = "O";}
    if (first_player == "X" || first_player == "O") {
      valid_input = true;
    } else {
      cout << "Invalid input. Please enter 'X' or 'O'." << endl;
    }
  }

  //starts the game by calling the start_game function in the TicTacToe class using the game object
  game.start_game(first_player);

  //code to prompt user for board position and calls functions in TicTacToe class to run game
  while (!game.game_over()) {
    do {
    cout << "Enter position (1-9) for player " << game.get_player() << ": ";
    cin >> position;
    if (position > 9 && position < 1) {cout << position << " is not a valid board position." << endl;}
    } while(position > 9 || position < 1);
    game.mark_board(position);
    game.display_board();
  }
  //when the game is over will display who won or tie
  cout << "Game over!" << endl;
  if (game.get_winner() == "C") {
    cout << "Tie game." << endl;
  } else {
    cout << "Player " << game.get_winner() << " wins!" << endl;
  }

  //user input and while loop (input validation) to ask user to restart program
  cout << "would you like to play again? (y/n): ";
  cin >> exitOption;
  while (exitOption != "Y" && exitOption != "y" && exitOption != "N" && exitOption != "n") {
      cout << "Please put in a valid input (y/n): ";
      cin >> exitOption;}
  valid_input = false; //so game will ask for first player again
} while(exitOption == "Y" || exitOption == "y");

return 0;
}
