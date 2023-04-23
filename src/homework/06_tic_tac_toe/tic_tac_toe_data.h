#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

#include <fstream>
#include <memory>
#include <vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

using std::vector;

class TicTacToeData
{
public:
    void save_games(const vector<std::unique_ptr<TicTacToe>>& games);
    vector<std::unique_ptr<TicTacToe>> get_games();
};

#endif
