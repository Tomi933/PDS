#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

bool isSafe(int board[], int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
        int qCol = board[i];
        if (qCol == col || abs(qCol - col) == abs(i - row))
            return false;
    }
    return true;
}

void printBoard(int board[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int board[], int row, int n, int& solutions) {
    if (row == n) {
        printBoard(board, n);
        solutions++;
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, solutions);
        }
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть n: ";
    cin >> n;

    int board[20];
    int solutions = 0;

    solveNQueens(board, 0, n, solutions);

    cout << "Загальна кількість розв'язків: " << solutions << endl;
    return 0;
}
