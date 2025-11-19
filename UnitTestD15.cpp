#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD15/ProjectD15.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD15
{
	TEST_CLASS(UnitTestD15)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 4;
			int board[20] = { -1, -1, -1, -1 };
			board[0] = 1; 

		
			int row = 1;
			int col = 3; 
			Assert::IsTrue(isSafe(board, row, col, n));
		}
	};
}
