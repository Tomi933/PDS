#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectD6/ProjectD6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestD6
{
	TEST_CLASS(UnitTestD6)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int MAX = 100;
			int n = 3, m = 2;
			int edges[MAX][2] = { {1, 2}, {2, 3} };
			int adj[MAX][MAX] = { 0 };

			int result = buildAdjacencyMatrix(n, m, edges, adj);

			// Перевіряємо, що матриця побудована правильно:
			Assert::AreEqual(1, adj[0][1], L"Помилка: ребро 1->2 відсутнє");
			Assert::AreEqual(1, adj[1][2], L"Помилка: ребро 2->3 відсутнє");
			Assert::AreEqual(0, adj[0][2], L"Помилка: непотрібне ребро 1->3");

			// Перевіряємо результат функції (сума індексів вершин)
			Assert::AreEqual(1, result, L"Помилка: функція повертає неправильну суму");
		}
	};
}
