#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
//#include <string.h>
//#include <algorithm>
#include "tic_tac_toe.cpp"
#include "tic_tac_toe.h"

using std::cout; using std::cin;
using std::endl;
using std::string;


int main() {
TicTacToe game;
string first_player;
cout << "Welcome to Tic Tac Toe!\n";
cout << "Player 1, please choose X or O: ";
cin >> first_player;
game.start_game(first_player);

int position = 0;
while(!game.game_over()) {
    game.display_board();
    cout << "Current player: " << game.get_player() << endl;
    cout << "Enter a position (1-9): ";
    cin >> position;
    game.mark_board(position);
}

game.display_board();

if (game.check_board_full()) {
    cout << "The game is a tie!" << endl;
}
else {
    cout << "The winner is player " << game.get_player() << "!" << endl;
}

return 0;
}
