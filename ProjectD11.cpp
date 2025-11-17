#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
using namespace std;

const int MAX = 100;
const int INF = 100000;

int distMatrix[MAX][MAX];
int nextMatrix[MAX][MAX];
int n, m;

void readGraph(const char* filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Помилка відкриття файлу!\n";
        exit(1);
    }

    fin >> n >> m;

   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) 
                distMatrix[i][j] = 0;
            else 
                distMatrix[i][j] = INF;
            nextMatrix[i][j] = -1;
        }

    
    for (int k = 0; k < m; k++) {
        int v, u, w;
        fin >> v >> u >> w;
        v--; u--;
        distMatrix[v][u] = w;
        nextMatrix[v][u] = u;
    }

    fin.close();
}

void floydWarshall() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (distMatrix[i][k] + distMatrix[k][j] < distMatrix[i][j]) {
                    distMatrix[i][j] = distMatrix[i][k] + distMatrix[k][j];
                    nextMatrix[i][j] = nextMatrix[i][k];
                }
}

void printDistMatrix() {
    cout << "\nМатриця найкоротших відстаней (Floyd–Warshall):\n\n";

    cout << "       ";
    for (int j = 0; j < n; j++)
        cout << j + 1 << setw(6);
    cout << endl;

    cout << " ";
    for (int j = 0; j < n; j++) cout << "-----";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(2) << i + 1 << " |   ";

        for (int j = 0; j < n; j++) {
            if (distMatrix[i][j] >= INF)
                cout << setw(6) << "INF";
            else
                cout << left << setw(6) << distMatrix[i][j];
        }
        cout << endl;
    }
}



void printPath(int u, int v) {
    if (nextMatrix[u][v] == -1) {
        cout << "Шлях відсутній\n";
        return;
    }

    cout << "Шлях: " << u + 1;
    while (u != v) {
        u = nextMatrix[u][v];
        cout << " -> " << u + 1;
    }
    cout << endl;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    readGraph("Text.txt");

    floydWarshall();
    printDistMatrix();

    int s, t;
    cout << "\nВведіть початкову вершину: ";
    cin >> s;
    cout << "Введіть кінцеву вершину: ";
    cin >> t;

    s--; t--;

    if (distMatrix[s][t] >= INF)
        cout << "Шляху немає\n";
    else {
        cout << "Найкоротша відстань: " << distMatrix[s][t] << endl;
        printPath(s, t);
    }
    return 0;
}
