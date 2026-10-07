#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

class Board {
    std::vector<char> board;

    public:
    Board();

    void printBoard();
    bool isFull();
    bool placeMove(int position, char player);
    bool checkWin(char player);
    void undoMove(int position);
    int evaluate(char aiPlayer, char humanPlayer);
};

#endif