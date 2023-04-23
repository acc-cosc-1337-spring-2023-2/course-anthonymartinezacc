#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"

using std::string;
using std::vector;

void TicTacToeData::save_games(const vector<std::unique_ptr<TicTacToe>>& games) {
    std::ofstream file("games.txt");

    if (file.is_open()) {
        for (const auto& game : games) {
            auto pegs = game->get_pegs();
            for (const auto& peg : pegs) {
                file << peg;
            }
            file << game->get_winner() << std::endl;
        }
        file.close();
    }
}

    vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games() {
    vector<std::unique_ptr<TicTacToe>> games;
    std::ifstream file("games.txt");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> pegs;
            for (size_t i = 0; i < line.size() - 1; i++) {
                pegs.push_back(string(1, line[i]));
            }
            string winner(1, line[line.size() - 1]);

            std::unique_ptr<TicTacToe> board;
            if (pegs.size() == 9) {
                board = std::make_unique<TicTacToe3>(pegs, winner);
            }
            else if (pegs.size() == 16) {
                board = std::make_unique<TicTacToe4>(pegs, winner);
            }
            games.push_back(std::move(board));
        }
        file.close();
    }
    return games;
}
