#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD8/ProjectD8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD8
{
	TEST_CLASS(UnitTestD8)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			push(7);
			push(2);
			push(9);
			push(2);

			int sum = stackArr[0] + stackArr[1] + stackArr[2] + stackArr[3];

			Assert::AreEqual(20, sum);
		}
	};
}
