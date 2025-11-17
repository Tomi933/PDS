#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD10/ProjectD10.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			
			int W[MAX][MAX];

			Assert::AreEqual(36, createMatrix(6, W));

		}
	};
}
