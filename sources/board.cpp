#include "board.hpp"
#include "macros.hpp"
#include <iostream>

Board::Board(): board(BOARD_SIZE, ' '){}

void Board::printBoard(){
    for (unsigned i=0; i<BOARD_SIZE; i++){
        std::cout << '[' << board[i] << ']';
        if ((i+1)%3==0){
            std::cout << '\n';
        }
    }
}

bool Board::isFull(){
    for (char b : board){
        if (b==' '){
            return false;
        }
    }
    return true;
}

bool Board::placeMove(int position, char player){
    if (position>=0 and position<BOARD_SIZE and board[position]==' '){board[position]=player; return true;} // set player character
    return false; // out of bound or invalid position
}

bool Board::checkWin(char player){
    return (
        // row
        (board[0]==player and board[1]==player and board[2]==player) or
        (board[3]==player and board[4]==player and board[5]==player) or
        (board[6]==player and board[7]==player and board[8]==player) or
        // column
        (board[0]==player and board[3]==player and board[6]==player) or
        (board[1]==player and board[4]==player and board[7]==player) or
        (board[2]==player and board[5]==player and board[8]==player) or
        // diagonal
        (board[0]==player and board[4]==player and board[8]==player) or
        (board[6]==player and board[4]==player and board[2]==player)
    );
}