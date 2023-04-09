//header file for tic tac toe game program
//contributors: anthony
//progress: active devlopment

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class TicTacToe {
public:
    TicTacToe();

    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const;
    string get_winner() const;
    //void display_board() const;
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);

private:
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    void set_winner();
    void set_next_player();
    bool check_board_full();
    void clear_board();

    vector<string> pegs;
    string player;
    string winner;
};

class TicTacToeManager
{
    public:
        void save_game(TicTacToe b);
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
        void get_winner_total(int& o, int& w, int& t);

    private:
        void update_winner_count(string winner);

        vector<TicTacToe> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
};

#endif
