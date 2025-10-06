#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD3/ProjectD3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3D
{
	TEST_CLASS(UnitTest3D)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			/*int n = 6;
			int r = 5;
			double result = P1(n) * 1.0 / P2(n, r);

			Assert::AreEqual(result, 720.0);*/

			long long F[MAX_N + 1][MAX_N + 1] = { 0 };

			initializeF(F, 6);

			Assert::AreEqual(initializeF(F, 6), 12);
		}
	};
}
