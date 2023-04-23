//header file for tic tac toe game 3x3 board
//contributors: anthony
//progress: active devlopment

#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.h"

using std::string;
using std::vector;

#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

class TicTacToe3 : public TicTacToe
{
    public:
        TicTacToe3() : TicTacToe(3) {}
        TicTacToe3(vector<string> p, string winner);

    private:
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
};

#endif
