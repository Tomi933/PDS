#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD9/ProjectD9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD9
{
	TEST_CLASS(UnitTestD9)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			pushQueue(32);
			pushQueue(32);
			pushQueue(32);
			pushQueue(32);

			int sum = queueArr[0] + queueArr[1] + queueArr[2] + queueArr[3];

			Assert::AreEqual(128, sum);


		}
	};
}
