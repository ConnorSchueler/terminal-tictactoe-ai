#include "board.hpp"
#include "ai.hpp"
#include <iostream>

int main(){
    Board board;
    char currentPlayer='X';
    int chosenPosition;

    while(!board.isFull()){
        board.printBoard();
        if (currentPlayer=='X'){
            // human playing
            std::cout << "[Player " << currentPlayer << "]: Choose a position (1-9)   >";
            std::cin >> chosenPosition;
            if(!board.placeMove(chosenPosition-1, currentPlayer)){
                std::cout << "Invalid position! Try again!" << std::endl;
                continue;
            };
        }else {
            // ai playing
            std::cout << "AI is thinking..." << std::endl;
            int aiMove = AI::getBestMove(board, 'O', 'X');
            board.placeMove(aiMove, 'O');
        }
        if (board.checkWin(currentPlayer)){
            board.printBoard();
            std::cout << "[Player " << currentPlayer << "] wins!" << std::endl;
            return 0;
        }
        if (currentPlayer=='X'){currentPlayer='O';} else {currentPlayer='X';}
    }
    std::cout << "The game ends in a draw!" << std::endl;
}