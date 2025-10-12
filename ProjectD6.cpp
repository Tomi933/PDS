#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

const int MAX = 100; 


void readGraph(const string& filename, int& n, int& m, int edges[][2]) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Помилка: не вдалося відкрити файл " << filename << endl;
        exit(1);
    }

    fin >> n >> m;
    if (n > MAX || m > MAX) {
        cerr << "Помилка: перевищено допустимий розмір графа (максимум 100)." << endl;
        exit(1);
    }

    for (int i = 0; i < m; i++)
        fin >> edges[i][0] >> edges[i][1];

    fin.close();
}


int buildAdjacencyMatrix(int n, int m, int edges[][2], int adj[][MAX]) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        adj[u][v] = 1;
        count += u;
    }
    return count;
}


void buildIncidenceMatrix(int n, int m, int edges[][2], int inc[][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            inc[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        inc[u][i] = -1; 
        inc[v][i] = 1;  
    }
}


void printMatrix(int rows, int cols, int matrix[][MAX], const string& name, const string& outFile = "") {
    cout << "\n" << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    if (!outFile.empty()) {
        ofstream fout(outFile, ios::app);
        fout << "\n" << name << ":\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                fout << matrix[i][j] << " ";
            fout << "\n";
        }
        fout.close();
    }
}

int main() {
    SetConsoleOutputCP(1251);

    string inFile, outFile;
    cout << "Введіть назву вхідного файлу: ";
    cin >> inFile;

    int n, m;
    int edges[MAX][2];
    int adjacency[MAX][MAX];
    int incidence[MAX][MAX];

    readGraph(inFile, n, m, edges);
    buildAdjacencyMatrix(n, m, edges, adjacency);
    buildIncidenceMatrix(n, m, edges, incidence);

    cout << "\nБажаєте зберегти результати у файл? (1/ні): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Введіть назву вихідного файлу: ";
        cin >> outFile;
        ofstream clear(outFile, ios::trunc);
        clear.close();
    }

    printMatrix(n, n, adjacency, "Матриця суміжності", outFile);
    printMatrix(n, m, incidence, "Матриця інцидентності", outFile);

    cout << "\nРоботу завершено.\n";
    return 0;
}
