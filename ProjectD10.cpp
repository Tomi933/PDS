#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

const int MAX = 100;
const int INF = 0;

bool readGraph(const string& filename, int& n, int& m, int edges[][3]) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Помилка: не вдалося відкрити файл " << filename << endl;
        return false;
    }

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        fin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    fin.close();
    return true;
}


int createMatrix(int n, int W[][MAX]) {

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            W[i][j] = INF;
            count++;
        }
    }

    return count;
}


void buildWeightMatrix(int n, int m, int edges[][3], int W[][MAX]) {
    

    createMatrix(n, W);

    
    for (int i = 0; i < m; i++) {
        int u = edges[i][0] - 1; 
        int v = edges[i][1] - 1;
        int w = edges[i][2];
        W[u][v] = w;
    }

    
}

void printMatrix(int n, int W[][MAX], const string& outFile) {
    ofstream fout(outFile);
    if (!fout.is_open()) {
        cerr << "Помилка відкриття файлу для запису.\n";
        return;
    }

    cout << "Матриця ваг:" << endl;
    fout << "Матриця ваг:" << endl;

    cout << setw(5) << " ";
    fout << setw(5) << " ";
    for (int j = 0; j < n; j++) {
        cout << setw(5) << j + 1;
        fout << setw(5) << j + 1;
    }
    cout << endl;
    fout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(5) << i + 1;
        fout << setw(5) << i + 1;
        for (int j = 0; j < n; j++) {
            cout << setw(5) << W[i][j];
            fout << setw(5) << W[i][j];
        }
        cout << endl;
        fout << endl;
    }
    fout.close();
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inFile = "Text.txt";
    string outFile = "Text1.txt";

    int n, m;
    int edges[MAX][3];
    int W[MAX][MAX];

    if (!readGraph(inFile, n, m, edges)) return 1;

    buildWeightMatrix(n, m, edges, W);
    printMatrix(n, W, outFile);

    cout << "\nРезультати також записано у файл: " << outFile << endl;
    return 0;
}
