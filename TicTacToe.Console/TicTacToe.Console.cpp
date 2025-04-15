#include <iostream>
#include <vector>
#include "../TicTacToe.Logic/Board.h"

void DisplayBoard(Board board);
void GetPlayerMove(int& row, int& col);



int main() {
    Board board;

    int currentPlayer = 1;
    int row, col;

    while (board.GameStatus() == ' ') {
        // Display the board
        char token = (currentPlayer == 1) ? 'X' : 'O';
        std::cout << "Player " << token << "'s turn:\n";
        DisplayBoard(board);

        // Get player's move
        GetPlayerMove(row, col);

        // Check if the move is valid and update the board
        if (board.SetSquare(row, col, token)) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
        else {
            std::cout << "Invalid move! Please try again.\n";
        }
    }

    // Display the final board
    std::cout << "Game Over!" << std::endl;
    if (board.GameStatus() == 'T') {
        std::cout << "Game is a draw." << std::endl;
    }
    else {
        std::cout << "Player " << board.GameStatus() << " wins" << std::endl;
    }
    std::cout << "Final Board:" << std::endl;
    DisplayBoard(board);

    return 0;
}


// Function to display the TicTacToe board
void DisplayBoard(Board board) {
    std::cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board.GetSquare(i, j);
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  -----\n";
    }
    std::cout << std::endl;
}

// Function to get player's move
void GetPlayerMove(int& row, int& col) {
    std::cout << "Enter row and column(1 - 3) : ";
    std::cin >> row >> col;
    --row; // Adjusting for zero-based indexing
    --col;
}
