#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

bool* createMatrix(int n) {
    bool* a = new bool[n * n];
    for (int i = 0; i < n * n; i++)
        a[i] = false;
    return a;
}

void readGraph(const char* filename, bool* adj, int n, int m) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Помилка відкриття файлу!\n";
        exit(1);
    }

    int v, u;
    for (int i = 0; i < m; i++) {
        fin >> v >> u;
        if (v < 1 || v > n || u < 1 || u > n) {
            cout << "Невірні вершини у файлі!\n";
            exit(1);
        }
        adj[(v - 1) * n + (u - 1)] = true;
    }
}

bool isIrreflexive(bool* adj, int n) {
    for (int i = 0; i < n; i++)
        if (adj[i * n + i])
            return false;
    return true;
}

bool isAntisymmetric(bool* adj, int n) {
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a != b && adj[a * n + b] && adj[b * n + a])
                return false;
        }
    }
    return true;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "Text.txt";
    
    ifstream fin(filename.c_str());
    if (!fin) {
        cout << "Помилка відкриття файлу!\n";
        return 1;
    }

    int n, m;
    fin >> n >> m;
    fin.close();

    bool* adj = createMatrix(n);

    readGraph(filename.c_str(), adj, n, m);

    cout << "Відношення іррефлексивне: "
        << (isIrreflexive(adj, n) ? "ТАК" : "НІ") << endl;

    cout << "Відношення антисиметричне: "
        << (isAntisymmetric(adj, n) ? "ТАК" : "НІ") << endl;

    delete[] adj;
    return 0;
}
