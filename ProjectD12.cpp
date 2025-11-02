#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

const int INF = 1000000000; 
const int MAXN = 100;       

int n, m;
int graph[MAXN][MAXN];
int distArr[MAXN];
bool visited[MAXN];
int parent[MAXN];

bool hasNegativeEdge() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (graph[i][j] != INF && graph[i][j] < 0)
                return true;
    return false;
}


int findMinDist() {
    int minVal = INF, minIndex = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && distArr[i] < minVal) {
            minVal = distArr[i];
            minIndex = i;
        }
    }
    return minIndex;
}


void dijkstra(int start) {
    for (int i = 1; i <= n; i++) {
        distArr[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    distArr[start] = 0;

    for (int i = 1; i <= n - 1; i++) {
        int u = findMinDist();
        if (u == -1) break;
        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INF && distArr[u] + graph[u][v] < distArr[v]) {
                distArr[v] = distArr[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}


void printPath(int start, int end) {
    if (distArr[end] == INF) {
        cout << "Немає шляху з " << start << " до " << end << endl;
        return;
    }

    int path[MAXN], length = 0;
    for (int v = end; v != -1; v = parent[v])
        path[length++] = v;

    cout << "Найкоротший шлях (" << distArr[end] << "): ";
    for (int i = length - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin("Text.txt");
    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    fin >> n >> m;

    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = INF;

    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        graph[u][v] = w; 
        
    }

    fin.close();

    int start, end;
    cout << "Введіть початкову вершину: ";
    cin >> start;
    cout << "Введіть кінцеву вершину: ";
    cin >> end;

    if (hasNegativeEdge()) {
        cout << "\nУ графі є від’ємні ваги — алгоритм Дейкстри не може бути застосований.\n";
        return 0;
    }

    dijkstra(start);
    printPath(start, end);

    cout << "\nВідстані від вершини " << start << ":\n";
    for (int i = 1; i <= n; i++) {
        if (distArr[i] == INF)
            cout << i << ": недосяжна\n";
        else
            cout << i << ": " << distArr[i] << endl;
    }

    return 0;
}
