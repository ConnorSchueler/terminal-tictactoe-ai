# Tic-Tac-Toe AI 🤖

A terminal-based Tic-Tac-Toe engine written in C++. This project demonstrates advanced algorithmic concepts, specifically the implementation of an unbeatable AI opponent using the recursive Minimax algorithm. 

## ✨ Features
- **Unbeatable AI:** The computer calculates every possible future game state. It is mathematically impossible to beat; the best a human player can achieve is a draw.
- **Dynamic Play:** Users can choose to play as 'X' (going first) or 'O' (going second) at the start of each match.
- **Robust Input Handling:** Bulletproof input handling ensures the game won't crash if a user accidentally types a letter or an invalid number.
- **Clean Interface:** Utilizes ANSI escape codes to redraw the board in place, ensuring a smooth, persistent terminal experience.

## 🧠 Technical Highlights
- **Minimax Algorithm:** Implemented a recursive game-tree search that evaluates terminal states (+10 for AI win, -10 for human win, 0 for draw) and returns the optimal minimax values back up the tree.
- **Object-Oriented Architecture:** Clean code separation between the `Board` state manager and the stateless `AI` decision engine.
- **Efficient Memory Layout:** The 3x3 grid is mapped to a flat 1D `std::vector` to optimize iteration speed during the thousands of recursive AI simulations.

## ⚙️ Requirements
- C++ compatible compiler (e.g., `g++` or `clang++`)
- Terminal with ANSI escape code support

## 🚀 Build & Run
```bash
make
./tictactoe
```

## Future Improvements 
- Implement Alpha-Beta Pruning 
- Add adjustable difficulty levels (e.g., Easy, Medium, Impossible)
