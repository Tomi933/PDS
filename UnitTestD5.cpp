#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD5/ProjectD5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD5
{
	TEST_CLASS(UnitTestD5)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            /*char A[3];
            char B[3];
            char C[2];
            int j = 0;
            string D[18];

			Assert::AreEqual(Decart(D, j, A, B, C), 18);*/

			int res = 0;
			int k = 1;
			int U[6] = {1,4,3,6,2,5};
			bubbleSort(U, 6);
			for (int i = 0; i < 6; i++) {

				if (U[i] == k) {
					res++;
					k++;
				}
			}

			Assert::AreEqual(res, 6);

		}
	};
}
