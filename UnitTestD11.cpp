#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD11/ProjectD11.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD11
{
	TEST_CLASS(UnitTestD11)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            

            n = 4;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j) distMatrix[i][j] = 0;
                    else distMatrix[i][j] = INF;

                    nextMatrix[i][j] = -1;
                }
            }

            distMatrix[0][1] = 5; nextMatrix[0][1] = 1;
            distMatrix[1][2] = 3; nextMatrix[1][2] = 2;
            distMatrix[2][3] = 1; nextMatrix[2][3] = 3;
            distMatrix[0][3] = 10; nextMatrix[0][3] = 3;

            floydWarshall();

            Assert::AreEqual(9, distMatrix[0][3]);  
          
		}
	};
}
