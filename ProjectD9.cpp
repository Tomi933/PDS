#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

const int MAXN = 100;
int graph[MAXN + 1][MAXN + 1];
int degree[MAXN + 1];
int queueArr[MAXN + 1];
int frontIndex = 0, backIndex = -1;


bool isEmptyQueue() { return frontIndex > backIndex; }
void pushQueue(int x) { queueArr[++backIndex] = x; }
int popQueue() { return queueArr[frontIndex++]; }

void printQueue() {
    for (int i = frontIndex; i <= backIndex; i++)
        cout << queueArr[i] << " ";
}


void bfs(int start, int n) {
    bool visited[MAXN + 1] = { false };
    int bfs_num[MAXN + 1] = { 0 };
    int counter = 0;

    pushQueue(start);
    visited[start] = true;

    cout << left << setw(17) << "Поточна вершина"
        << setw(15) << "BFS-номер"
        << "Вміст черги" << endl;
    cout << string(50, '-') << endl;

    while (!isEmptyQueue()) {
        int v = popQueue();
        bfs_num[v] = ++counter;

       
        for (int i = 0; i < degree[v]; i++) {
            int u = graph[v][i];
            if (!visited[u]) {
                visited[u] = true;
                pushQueue(u);
            }
        }

        
        cout << left << setw(17) << v
            << setw(15) << bfs_num[v];
        printQueue();
        cout << endl;
    }
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("graph.txt");
    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    int n, m;
    file >> n >> m;
    file.ignore();


    for (int i = 1; i <= n; i++) degree[i] = 0;

    int a, b;
    while (file >> a >> b) {
        graph[a][degree[a]++] = b;
        graph[b][degree[b]++] = a; 
    }

    int start;
    cout << "Введіть початкову вершину: ";
    cin >> start;

    cout << endl;
    bfs(start, n);

    return 0;
}
