#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool p = true;
			bool q = false;

			bool conjunction = Conjunction(p, q);

			Assert::AreEqual(true, false)
		}
	};
}
