#include <iostream>
#include <vector>
#include <string>
#include "tic_tac_toe.h"

using std::cout; using std::cin;
using std::endl;
using std::string;
using std::vector;

class TicTacToe {
private:
string player;
vector<string> pegs;

public:
TicTacToe() {
player = "";
pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
}

bool game_over() {
    return check_board_full();
}

void start_game(string &first_player) {
    do {
    if (first_player == "X" || first_player == "O") {
        player = first_player;
    }
    else {
        cout << "Invalid first player. Choose X or O." << endl;
        cout << "Player 1, please choose X or O: ";
        cin >> first_player;
    }
    } while (first_player != "X" && first_player != "O");
    clear_board();
}

void mark_board(int position) {
    if (position >= 1 && position <= 9) {
        pegs[position - 1] = player;
        set_next_player();
    }
    else {
        cout << "Invalid position. Choose a number between 1 and 9." << endl;
    }
}

string get_player() const {
    return player;
}

void display_board() const {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << endl << "---------" << endl;
        }
        cout << pegs[i];
        if (i % 3 != 2) {
            cout << " | ";
        }
    }
    cout << endl;
}

void set_next_player() {
    if (player == "X") {
        player = "O";
    }
    else {
        player = "X";
    }
}

bool check_board_full() {
    for (int i = 0; i < 9; i++) {
        if (pegs[i] == " ") {
            return false;
        }
    }
    return true;
}

void clear_board() {
    for (int i = 0; i < 9; i++) {
        pegs[i] = " ";
    }
}
};
