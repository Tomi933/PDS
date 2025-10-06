#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;



//int P1(int n)
//{
//    int P1 = 1;
//
//    for (int i = 1; i <= n; i++) {
//        P1 = P1 * i;
//    }
//
//    return P1;
//}
//
//int P2(int n, int r)
//{
//    int P2 = 1;
//
//    for (int i = 1; i <= n - r; i++) {
//        P2 = P2 * i;
//    }
//
//    return P2;
//}

const int MAX_N = 6;

int initializeF(long long F[][MAX_N + 1], int n) {
    int a = 0;
    for (int j = 1; j <= n; ++j) {
        F[j][1] = 1;
        F[j][j] = 1;

        a = a + F[j][1] + F[j][j];
    }
    return a;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*int n, r;
    
    cout << "Введіть n: "; cin >> n;
    cout << "Введіть r: "; cin >> r;

    double A = P1(n) * 1.0 / P2(n, r);
    
    cout << "A: " << A;*/
    

    
    int i = 1;
    
    int n = i + 5;
 
    long long F[MAX_N + 1][MAX_N + 1] = { 0 }; 
    long long B[MAX_N + 1] = { 0 };            

   
    initializeF(F, n);

    for (int j = 3; j <= n; ++j) {
        for (int k = 2; k < j; ++k) {
            F[j][k] = F[j - 1][k - 1] + k * F[j - 1][k];
        }
    }

    for (int j = 1; j <= n; ++j) {
        B[j] = 0;
    }

    
    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= j; ++k) {
            B[j] += F[j][k];
        }
    }

    
    cout << "\nТаблиця чисел Стірлінга другого роду (S(n, k)):\n\n";

    const int cellWidth = 8;

 
    cout << setw(cellWidth) << "n\\k" << " |";
    for (int k = 1; k <= n; ++k)
        cout << setw(cellWidth) << k << " |";
    cout << "\n";


    cout << setfill('-') << setw(cellWidth + 2 + n * (cellWidth + 2)) << "-" << endl;
    cout << setfill(' '); 

    
    for (int j = 1; j <= n; ++j) {
        cout << setw(cellWidth) << j << " |";
        for (int k = 1; k <= n; ++k) {
            if (k <= j)
                cout << setw(cellWidth) << F[j][k] << " |";
            else
                cout << setw(cellWidth) << " " << " |";
        }
        cout << "\n";
    }


    
    cout << "\nЧисла Белла:\n";
    for (int j = 1; j <= n; ++j) {
        cout << "B[" << j << "] = " << B[j] << "\n";
    }

    return 0;
}