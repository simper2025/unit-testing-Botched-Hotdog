#include "pch.h"
#include "Board.h"


void Board::SetBoard(char setup[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int ii = 0; ii < 3; ii++)
		{
			grid[i][ii] = setup[i][ii];
		}
	}
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
	char Result = ' ';
	
	int RowX;
	int RowO;
	for (int i = 0; i < 3; i++)  // Rows
	{
		for (int ii = 0; ii < 3; ii++)
		{
			if (grid[i][ii] != ' ')
			{
				char Player = grid[i][ii];

				(Player == 'X') ? RowX++ : RowO++;
			}

		}
	}

	int ColumnX;
	int ColumnO;
	for (int i = 0; i < 3; i++)  // Columns
	{
		for (int ii = 0; ii < 3; ii++)
		{
			if (grid[i][ii] != ' ')
			{
				char Player = grid[i][ii];

				(Player == 'X') ? RowX++ : RowO++;
			}
		}
	}
	
	if (grid[1][1] != ' ')  // Diagonal
	{
		char Player = grid[1][1];
		bool bHasDiagonal = false;

		if (bHasDiagonal) Result = Player;
	}
	
	return Result;
}

