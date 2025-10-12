#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD4/ProjectD4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD4
{
	TEST_CLASS(UnitTestD4)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 2;
			
			int a[20];
			Assert::AreEqual(firstNum(a, n), 3);
		}
	};
}
