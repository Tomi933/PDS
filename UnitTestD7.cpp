#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD7/ProjectD7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD7
{
	TEST_CLASS(UnitTestD7)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int MAX = 100;

			string filename = "Text.txt";
			int n, m;
			int edges[MAX][2];
			int adj[MAX][MAX];
			int outDeg[MAX], inDeg[MAX];
			int degree;

			if (!readGraph(filename, n, m, edges)) {
				cout << "Помилка: не вдалося відкрити файл.\n";
			}

			buildAdjMatrix(n, m, edges, adj);
			calcDegrees(n, adj, outDeg, inDeg);

			Assert::AreEqual(isRegular(n, outDeg, inDeg, degree), true);
		}
	};
}
