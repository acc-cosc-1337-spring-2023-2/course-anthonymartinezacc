#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#include "tic_tac_toe.cpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify That board fills up") {
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");

    tictactoegame.mark_board(1);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(3);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(4);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(9);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(8);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "C");
}

TEST_CASE("verify Test win diagonally from top left to bottom right")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");

    tictactoegame.mark_board(1);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(9);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");
}

TEST_CASE("verify Test win diagonally from bottom left to top right")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(3);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");
}

TEST_CASE("verify Test win by first row")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");

    tictactoegame.mark_board(1);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(4);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");
}

TEST_CASE("verify Test win by second row")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");

    tictactoegame.mark_board(4);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");
}

TEST_CASE("verify Test win by third row")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(8);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(4);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(9);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");
}

TEST_CASE("verify Test win by first column")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");

    tictactoegame.mark_board(1);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(4);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");
}

TEST_CASE("verify Test win by second column")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(1);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(8);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");
}

TEST_CASE("verify Test win by third column")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("O");

    tictactoegame.mark_board(3);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(1);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(9);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "O");
}

TEST_CASE("verify Test first player X")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("X");
    REQUIRE(tictactoegame.get_player() == "X");
}

TEST_CASE("verify Test first player O")
{
    TicTacToe tictactoegame;

    tictactoegame.start_game("O");
    REQUIRE(tictactoegame.get_player() == "O");
}



TEST_CASE("verify that count is working")
{
    TicTacToe tictactoegame;
    TicTacToeManager manager;
    int w = 0;                //used to display the number of times x won
    int o = 0;                //used to display the number of times o won
    int t = 0;                //used to display the number of ties

    tictactoegame.start_game("O");

    tictactoegame.mark_board(3);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(1);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(9);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "O");

    manager.save_game(tictactoegame);


    tictactoegame.start_game("X");

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(1);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(8);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");

    manager.save_game(tictactoegame);


    tictactoegame.start_game("X");

    tictactoegame.mark_board(4);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(2);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(5);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(7);
    REQUIRE(tictactoegame.game_over() == false);

    tictactoegame.mark_board(6);
    REQUIRE(tictactoegame.game_over() == true);
    REQUIRE(tictactoegame.get_winner() == "X");

    manager.save_game(tictactoegame);

    manager.get_winner_total(o, w, t);
    REQUIRE(o == 1);
    REQUIRE(w == 2);
    REQUIRE(t == 0);

}

