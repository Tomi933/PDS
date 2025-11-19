#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

const int MAXN = 100;

int graph[MAXN][MAXN];
int color[MAXN];
int n, m;


bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

bool colorGraph(int v, int maxColors) {
    if (v == n)
        return true;

    for (int c = 1; c <= maxColors; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (colorGraph(v + 1, maxColors))
                return true;

            color[v] = 0;
        }
    }
    return false;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin("Text.txt");
    if (!fin) {
        cout << "Помилка: не можу відкрити input.txt\n";
        return 1;
    }

    fin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int v, u;
        fin >> v >> u;
        graph[v][u] = 1;
        graph[u][v] = 1;
    }

    fin.close();

    int chromatic = 1;

    while (true) {
        for (int i = 0; i < n; i++)
            color[i] = 0;

        if (colorGraph(0, chromatic))
            break;

        chromatic++;
    }

    cout << "Мінімальна кількість кольорів: " << chromatic << "\n";
    cout << "Розфарбування вершин:\n";

    for (int i = 0; i < n; i++)
        cout << "Вершина " << i << " -> колір " << color[i] << "\n";

    return 0;
}
