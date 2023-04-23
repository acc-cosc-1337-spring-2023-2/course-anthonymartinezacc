//header file for tic tac toe game program
//contributors: anthony
//progress: active devlopment

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;


class TicTacToe
{
    public:
        friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);
        friend std::istream& operator>>(std::istream& is, TicTacToe& game);
        TicTacToe(vector<string> p, string win);
        vector<string> get_pegs() const;
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        //void display_board() const;
        bool game_over();
        string get_winner() const;

        TicTacToe() = default;
        TicTacToe(int size) : pegs(size * size, " ") {}

     protected:
        vector<string> pegs;

        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();
        void set_winner();

    private:
        string player;
        string winner;

        void set_next_player();
        bool check_board_full();
        void clear_board();
};

#endif
