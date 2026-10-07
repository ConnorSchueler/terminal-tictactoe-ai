#ifndef AI_HPP
#define AI_HPP

#include "board.hpp"
#include "macros.hpp"

class AI{
    static int minimax(Board& board, bool isMaximizing, char aiPlayer, char humanPlayer);

    public:
    static int getBestMove(Board& board, char aiPlayer, char humanPlayer);

};
#endif