#include "pch.h"
#include "CppUnitTest.h"
#include "../TicTacToe.Logic/Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToeTest
{
	TEST_CLASS(TicTacToeTest)
	{
	public:

		TEST_METHOD(TestTrue)
		{
			Assert::AreEqual(true, true);
		}

		TEST_METHOD(TestSetSquare)
		{
			//Arrange
			Board b;
			
			//Act
			b.SetSquare(0, 0, 'X');
		
			//Assert
			Assert::AreEqual('X', b.GetSquare(0,0));
		}

		//TEST_METHOD(TestBoardCreate)
		//{
		//	Board b;
		//	char setup[3][3] = { {'X',' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
		//	b.SetBoard(setup);
		//	Assert::AreEqual('X', b.GetSquare(0, 0));
		//}

	};
}
