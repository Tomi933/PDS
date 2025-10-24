#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

const int MAXN = 100;  
const int MAXM = 100;  

int graph[MAXN + 1][MAXN + 1]; 
int degree[MAXN + 1];         

int stackArr[MAXN + 1];
int topIndex = -1;

void push(int v) {
    stackArr[++topIndex] = v;
}

int pop() {
    if (topIndex == -1) return -1;
    return stackArr[topIndex--];
}

bool isEmpty() {
    return topIndex == -1;
}

void printStack() {
    for (int i = topIndex; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
}


void dfs(int start, int n) {
    bool visited[MAXN + 1] = { false };
    int dfs_num[MAXN + 1] = { 0 };
    int counter = 0;

    push(start);

    cout << left << setw(17) << "Поточна вершина"
        << setw(15) << "DFS-номер"
        << "Вміст стеку" << endl;
    cout << string(50, '-') << endl;

    while (!isEmpty()) {
        int v = pop();

        if (!visited[v]) {
            visited[v] = true;
            dfs_num[v] = ++counter;

            
            for (int i = degree[v] - 1; i >= 0; i--) {
                int u = graph[v][i];
                if (!visited[u]) push(u);
            }

            
            cout << left << setw(17) << v
                << setw(15) << dfs_num[v];
            printStack();
            cout << endl;
        }
    }
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("graph.txt");
    if (!file.is_open()) {
        cerr << "Помилка: не вдалося відкрити файл graph.txt" << endl;
        return 1;
    }

    int n, m;
    file >> n >> m;

    
    for (int i = 1; i <= n; i++) degree[i] = 0;

   
    for (int i = 0; i < m; i++) {
        int a, b;
        file >> a >> b;
        
        graph[a][degree[a]++] = b;
        graph[b][degree[b]++] = a;
    }

    int start;
    cout << "Введіть початкову вершину: ";
    cin >> start;

    dfs(start, n);

    

    return 0;
}