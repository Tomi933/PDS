#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

const int MAX = 100;

bool readGraph(const string& filename, int& n, int& m, int edges[][2]) {
    ifstream fin(filename);
    if (!fin.is_open()) return false;
    fin >> n >> m;
    for (int i = 0; i < m; i++)
        fin >> edges[i][0] >> edges[i][1];
    fin.close();
    return true;
}

void buildAdjMatrix(int n, int m, int edges[][2], int adj[][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        adj[u][v] = 1;
    }
}

void calcDegrees(int n, int adj[][MAX], int outDeg[], int inDeg[]) {
    for (int i = 0; i < n; i++) {
        outDeg[i] = 0;
        inDeg[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) outDeg[i]++;
            if (adj[j][i]) inDeg[i]++;
        }
    }
}

bool isRegular(int n, int outDeg[], int inDeg[], int& degree) {
    degree = outDeg[0] + inDeg[0];
    for (int i = 1; i < n; i++) {
        if (outDeg[i] + inDeg[i] != degree)
            return false;
    }
    return true;
}

void findSpecialVertices(int n, int outDeg[], int inDeg[]) {
    cout << "\nІзольовані вершини: ";
    bool foundIso = false;
    for (int i = 0; i < n; i++) {
        if (outDeg[i] == 0 && inDeg[i] == 0) {
            cout << i + 1 << " ";
            foundIso = true;
        }
    }
    if (!foundIso) cout << "немає";

    cout << "\nВисячі вершини: ";
    bool foundHang = false;
    for (int i = 0; i < n; i++) {
        if (outDeg[i] + inDeg[i] == 1) {
            cout << i + 1 << " ";
            foundHang = true;
        }
    }
    if (!foundHang) cout << "немає";
    cout << endl;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "Text.txt";
    int n, m;
    int edges[MAX][2];
    int adj[MAX][MAX];
    int outDeg[MAX], inDeg[MAX];

    if (!readGraph(filename, n, m, edges)) {
        cout << "Помилка: не вдалося відкрити файл.\n";
        return 1;
    }

    buildAdjMatrix(n, m, edges, adj);
    calcDegrees(n, adj, outDeg, inDeg);

    cout << "Степені вершин:\n";
    cout << setw(10) << "Вершина" << setw(10) << "Вихід" << setw(10) << "Вхід" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(10) << i + 1 << setw(10) << outDeg[i] << setw(10) << inDeg[i] << endl;
    }

    int degree;
    if (isRegular(n, outDeg, inDeg, degree))
        cout << "\nГраф однорідний. Степінь однорідності = " << degree << endl;
    else
        cout << "\nГраф не є однорідним.\n";

    findSpecialVertices(n, outDeg, inDeg);

    return 0;
}
