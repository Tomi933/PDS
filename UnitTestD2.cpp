#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD2/ProjectD2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD2
{
	TEST_CLASS(UnitTestD2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(EquivalenceTable(), true);
		}
	};
}
