#include "pch.h"
#include "Board.h"


void Board::SetBoard(char setup[3][3])
{
	
}

char Board::GetSquare(int row, int col) const
{
	return grid[row][col];
}

bool Board::SetSquare(int row, int col, char player)
{
	bool Success = false;

	if (grid[row][col] == ' ')
	{
		grid[row][col] = player;
		Success = true;
	}

	return Success;
}

char Board::GameStatus()
{
	return ' ';
}

