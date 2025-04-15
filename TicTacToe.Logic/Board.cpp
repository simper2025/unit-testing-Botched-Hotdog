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
	
	int RowX = 0;
	int RowO = 0;
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

		if (RowX == 3)
		{
			Result = 'X';
			break;
		}
		else if (RowO == 3)
		{
			Result = 'O';
			break;
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

				(Player == 'X') ? ColumnX++ : ColumnO++;
			}
		}

		if (ColumnX == 3)
		{
			Result = 'X';
			break;
		}
		else if (ColumnO == 3)
		{
			Result = 'O';
			break;
		}
	}
	
	if (grid[1][1] != ' ')  // Diagonal
	{
		char Player = grid[1][1];

		bool PositiveDiagonal = (grid[2][0] == Player && grid[0][2] == Player);
		bool NegativeDiagonal = (grid[0][0] == Player && grid[2][2] == Player);
		
		if (PositiveDiagonal || NegativeDiagonal)
		{
			Result = Player;
		}
	}

	bool bIsBoardNotFull = false;
	for (int i = 0; i < 3; i++)  // Board Full
	{
		for (int ii = 0; ii < 3; ii++)
		{
			if (grid[i][ii] == ' ')
			{
				bIsBoardNotFull = true;
				break;
			}
		}
	}
	if (!bIsBoardNotFull)
	{
		Result = 'T';
	}
	
	return Result;
}

