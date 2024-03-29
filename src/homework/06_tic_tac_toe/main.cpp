//tic tac toe program that allows 2 players to play tic tac toe
//contributors: anthony
//progress: active devlopment

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include "tic_tac_toe.cpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.cpp"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.cpp"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.cpp"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_data.cpp"

using std::cout; using std::cin;
using std::endl;
using std::string;

int main() {
  std::unique_ptr<TicTacToe> tictactoegame; //object pointer from the TicTacToe Class
  TicTacToeData data;
  TicTacToeManager manager(data); //object from the TicTacToeManager Class
  string menuOption;        //user input for what to do on the menu
  string exitOption;        //var used to ask user if they would like to play again
  string first_player;      //var used to store if the first player would like to be a X or a O
  bool valid_input = false; //bool used to validate if the user put an X or O for first_player var
  int position;             //user input for board position
  int w = 0;                //used to display the number of times x won
  int o = 0;                //used to display the number of times o won
  int t = 0;                //used to display the number of ties
  int board_size;

  //do while loop for menu
  do {
  cout << "1. Play Tic Tac Toe 3\n"
       << "2. Play Tic Tac Toe 4\n"
       << "3. View Game History\n"
       << "4. Quit" << endl;
  //menu input, and invalid input message
  cout << "option: ";
  cin >> menuOption;
  //menuOption.erase(std::remove(menuOption.begin(),menuOption.end(),' '),menuOption.end()); //erases leading or trailing spaces
  if (menuOption != "4" && menuOption != "3" && menuOption != "2" && menuOption != "1") {cout << "please pict a valid option (1,2,3,4)\n";}
if (menuOption == "1" || menuOption == "2") {
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
  valid_input = false; //used so the program will ask if player is X or O again

  //starts the tictactoegame by calling the start_game function in the TicTacToe class using the tictactoegame object
  if (menuOption == "1"){
    board_size = 3;
    tictactoegame.reset(new TicTacToe3());
    tictactoegame = std::make_unique<TicTacToe3>();
  }
  if (menuOption == "2"){
    board_size = 4;
    tictactoegame.reset(new TicTacToe4());
    tictactoegame = std::make_unique<TicTacToe4>();
  }

  //tictactoegame = std::make_unique<TicTacToe>(board_size);
  tictactoegame->start_game(first_player);

  //code to prompt user for board position and calls functions in TicTacToe class to run tictactoegame
  do {
  cin  >> *tictactoegame;
  cout << "\n"
       << *tictactoegame << "\n";
  } while (!tictactoegame->game_over());

  //when the tictactoegame is over will display who won or tie
  cout << "Game over!" << endl;
  if (tictactoegame->get_winner() == "C") {
    //t++;
    cout << "Tie game." << endl;
  } else {
    cout << "Player " << tictactoegame->get_winner() << " wins!" << endl;
  }
  manager.save_game(tictactoegame);
  manager.get_winner_total(o, w, t);
  menuOption = "n";
}

if (menuOption == "3") {
  menuOption = "n";
  cout << manager;
}

//will ask the user to confirm exiting the program and will then exit
  if (menuOption == "4") {
    cout << "Are you sure you want to exit? (y/n): ";
    cin >> exitOption;
    //exitOption.erase(std::remove(exitOption.begin(),exitOption.end(),' '),exitOption.end()); //removes leading or trailing spaces
    while (exitOption != "Y" && exitOption != "y" && exitOption != "N" && exitOption != "n") {
        cout << "Please put in a valid input (y/n): ";
        cin >> exitOption;}
    //if (exitOption == 'Y' || exitOption == 'y') {menuOption = "3";}
    if (exitOption == "N" || exitOption == "n") {menuOption = "n";}
    //cout << "\n";
    manager.get_winner_total(o, w, t);
  }

} while(menuOption != "4" && menuOption != "3" && menuOption != "2" && menuOption != "1");;

return 0;
}
