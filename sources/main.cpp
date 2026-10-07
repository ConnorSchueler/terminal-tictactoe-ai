#include "board.hpp"
#include "ai.hpp"
#include <iostream>
#include <limits>

int main(){
    Board board;
    char currentPlayer='X';
    char humanPlayer = 'X';
    char aiPlayer = 'O';
    char choice;

    std::cout << "\033[2J\033[1;1H"; // clear screen
    std::cout << "Choose your symbol: 'X'(goes first) or 'O' (goes second)  >";
    std::cin >> choice;
    std::cin.ignore(1000, '\n'); // deletes possible remainder-input in buffer

    if (choice=='o' or choice=='O'){ // set to choice
        humanPlayer = 'O';
        aiPlayer = 'X';
    }


    int chosenPosition;

    while(!board.isFull()){
        board.printBoard();
        if (currentPlayer==humanPlayer){
            // human playing
            std::cout << "[Player " << currentPlayer << "]: Choose a position (1-9)  >";
            std::cin >> chosenPosition;

            // handle letters or symbols
            if(std::cin.fail()){
                std::cin.clear(); // clear failing status
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // delete wrong input in buffer
                std::cout << "Invalid input! Press Enter to continue...";
                std::cin.get();
                continue;
            }

            if(!board.placeMove(chosenPosition-1, currentPlayer)){
                std::cout << "Invalid position! Try again! Press Enter to continue..." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // delete wrong input in buffer
                std::cin.get();
                continue;
            };
        }else {
            // ai playing
            int aiMove = AI::getBestMove(board, aiPlayer, humanPlayer);
            board.placeMove(aiMove, aiPlayer);
        }
        if (board.checkWin(currentPlayer)){
            board.printBoard();
            std::cout << "[Player " << currentPlayer << "] wins!" << std::endl;
            return 0;
        }
        if (currentPlayer=='X'){currentPlayer='O';} else {currentPlayer='X';}
    }
    board.printBoard();
    std::cout << "The game ends in a draw!" << std::endl;
}