//header file for tic tac toe manager class
//contributors: anthony
//progress: active devlopment


#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"

using std::string;
using std::vector;

class TicTacToeManager
{
    public:
        TicTacToeManager();
        explicit TicTacToeManager(TicTacToeData& data);
        ~TicTacToeManager();
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
        void save_game(std::unique_ptr<TicTacToe>& b);
        void get_winner_total(int& o, int& w, int& t);

    private:
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        vector<std::unique_ptr<TicTacToe>> games;
        TicTacToeData data;

        void update_winner_count(string winner);
};

#endif
