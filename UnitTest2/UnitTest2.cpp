#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD1/D1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		/*TEST_METHOD(TestMethod1)
		{
			bool p = true;
			bool q = false;

			bool conjunction = Conjunction(p, q);

			Assert::AreEqual(conjunction, false);
		}*/

		TEST_METHOD(TestMethod2)
		{
			string a, b;
			a = "111100000";
			b = "101010011";

			int n = a.length();

			string  y = "", k = "101000000";

			string result = Update(y, a, b, n);

			Assert::AreEqual(result, k);
		}
	};
}
