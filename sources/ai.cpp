#include "ai.hpp"
#include <algorithm>

int AI::minimax(Board& board, bool isMaximizing, char aiPlayer, char humanPlayer){
    // base case:
    int score = board.evaluate(aiPlayer, humanPlayer); 

    if (score!=0){
        return score;
    }

    if (board.isFull()){
        return 0;
    }

    // recursive step
    if (isMaximizing){
        // AI playing
        int bestScore = -1000;
        int currentScore1;

        for (int i=0; i<BOARD_SIZE; i++){
            if(!board.placeMove(i, aiPlayer)){continue;}
            currentScore1 = minimax(board, false, aiPlayer, humanPlayer);
            board.undoMove(i);
            bestScore = std::max(bestScore, currentScore1);
        }
        return bestScore;
    } else {
        // "human" playing
        int bestScore = 1000;
        int currentScore2;

        for (int i=0; i<BOARD_SIZE; i++){
            if(!board.placeMove(i, humanPlayer)){continue;}
            currentScore2 = minimax(board, true, aiPlayer, humanPlayer);
            board.undoMove(i);
            bestScore = std::min(bestScore, currentScore2);
        }
        return bestScore;
    }
}

int AI::getBestMove(Board& board, char aiPlayer, char humanPlayer){
    int bestScore = -1000;
    int bestMove = -1;
    int score;

    for (int i=0; i<BOARD_SIZE; i++){
        if(!board.placeMove(i, aiPlayer)){continue;}
        score = minimax(board, false, aiPlayer, humanPlayer);
        board.undoMove(i);

        if(score>bestScore){
            bestScore=score;
            bestMove=i;
        }
    }
    return bestMove;
}