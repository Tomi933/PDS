#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD13/ProjectD13.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD13
{
	TEST_CLASS(UnitTestD13)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			n = 2;

			graph[0][0] = 0; 
			graph[0][1] = 1;
			graph[1][0] = 1; 
			graph[1][1] = 0;

			color[0] = 0;
			color[1] = 1;

			bool result = isSafe(0, 1); 

			Assert::AreEqual(result, false);
		}
	};
}
