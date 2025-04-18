#include "pch.h"
#include "CppUnitTest.h"
#include "../TicTacToe.Logic/Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToeTest
{
	TEST_CLASS(TicTacToeTest)
	{
	public:

		TEST_METHOD(TestTrue_Pass)
		{
			Assert::AreEqual(true, true);
		}

		TEST_METHOD(TestTrue_Fail)
		{
			Assert::AreEqual(false, true);
		}


		TEST_METHOD(TestSetSquare_Pass)
		{
			//Arrange
			Board b;
			
			//Act
			b.SetSquare(0, 0, 'X');
		
			//Assert
			Assert::AreEqual('X', b.GetSquare(0,0));
		}

		TEST_METHOD(TestSetSquare_Fail)
		{
			//Arrange
			Board b;

			//Act
			b.SetSquare(0, 0, 'X');

			//Assert
			Assert::AreEqual('X', b.GetSquare(0, 0));
		}


		TEST_METHOD(TestSetTwoSquares_Fail)
		{
			//Arrange
			Board b;

			//Act
			b.SetSquare(0, 0, 'X');
			b.SetSquare(0, 0, 'O');  // Cant Overwrite spot!

			//Assert
			Assert::AreEqual('O', b.GetSquare(0, 0));
		}

		TEST_METHOD(TestSetTwoSquares_Pass)
		{
			//Arrange
			Board b;

			//Act
			b.SetSquare(0, 0, 'X');
			b.SetSquare(2, 1, 'O');

			//Assert
			Assert::AreEqual('O', b.GetSquare(2, 1));
		}


		TEST_METHOD(TestBoardCreate)
		{
			Board b;
			char setup[3][3] = { {'X',' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GetSquare(0, 0));
		}

		TEST_METHOD(TestBoardCreate_1)
		{
			Board b;
			char setup[3][3] = { {' ','X',' '}, {'O', 'O', ' '}, {' ', 'O', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('O', b.GetSquare(1, 1));
		}

		TEST_METHOD(TestBoardCreate_3)
		{
			Board b;
			char setup[3][3] = { {'X',' ','O'}, {' ', 'X', ' '}, {'X', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GetSquare(2, 0));
		}


		TEST_METHOD(GameStatus_XRowWin)
		{
			Board b;
			char setup[3][3] = { {' ',' ',' '}, {'X', 'X', 'X'}, {' ', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GameStatus());
		}

		TEST_METHOD(GameStatus_XColumnWin)
		{
			Board b;
			char setup[3][3] = { {' ','X',' '}, {' ', 'X', ' '}, {' ', 'X', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GameStatus());
		}

		TEST_METHOD(GameStatus_XDiagonalWin)
		{
			Board b;
			char setup[3][3] = { {'X',' ',' '}, {' ', 'X', ' '}, {' ', ' ', 'X'} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GameStatus());
		}


		TEST_METHOD(GameStatus_YRowWin)
		{
			Board b;
			char setup[3][3] = { {' ',' ',' '}, {'O', 'O', 'O'}, {' ', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('O', b.GameStatus());
		}

		TEST_METHOD(GameStatus_YColumnWin)
		{
			Board b;
			char setup[3][3] = { {' ',' ','O'}, {' ', ' ', 'O'}, {' ', ' ', 'O'} };
			b.SetBoard(setup);
			Assert::AreEqual('O', b.GameStatus());
		}

		TEST_METHOD(GameStatus_YDiagonalWin)
		{
			Board b;
			char setup[3][3] = { {'O',' ',' '}, {' ', 'O', ' '}, {' ', ' ', 'O'} };
			b.SetBoard(setup);
			Assert::AreEqual('O', b.GameStatus());
		}


		TEST_METHOD(GameStatus_Tie)
		{
			Board b;
			char setup[3][3] = { {'X','X','O'}, {'O', 'O', 'X'}, {'X', 'O', 'X'} };
			b.SetBoard(setup);
			Assert::AreEqual('T', b.GameStatus());
		}
	};
}
