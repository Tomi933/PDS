#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD14/ProjectD14.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD14
{
	TEST_CLASS(UnitTestD14)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 3;
			bool adj[9] = {
				false, true,  false,
				false, false, true,
				true,  false, false
			};

			Assert::IsTrue(isIrreflexive(adj, n));
		}
	};
}
