#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

const int MAX_N = 100; 


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмін
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//int Decart(string D[], int j, char A[3], char B[3], char C[2]) {
//    int count = 0;
//    for (int ia = 0; ia < 3; ia++) {
//        for (int ib = 0; ib < 3; ib++) {
//            for (int ic = 0; ic < 2; ic++) {
//                D[j] = string(1, A[ia]) + B[ib] + C[ic];
//                j++;
//                count++;
//            }
//        }
//    }
//    return count;
//}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*char A[3];
    cout << "Введіть елементи множини A (3 літери): ";
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    char B[3];
    cout << "Введіть елементи множини B (3 літери): ";
    for (int i = 0; i < 3; i++) {
        cin >> B[i];
    }

    char C[2];
    cout << "Введіть елементи множини C (2 символи): ";
    for (int i = 0; i < 2; i++) {
        cin >> C[i];
    }

    int j = 0;

    string D[18];

    Decart(D, j, A, B, C);

    cout << "\nДекартовий добуток A * B * C:\n";
    for (int i = 0; i < 18; i++) {
        cout << "D[" << i + 1 << "] = " << D[i] << endl;
    }*/

    // 1. Початок


    int n;
    int U[MAX_N];       // Універсум
    int A[MAX_N];       // Множина A
    int B[MAX_N];       // Множина B
    int Abit[MAX_N];    // Бітовий рядок A
    int Bbit[MAX_N];    // Бітовий рядок B
    int notA[MAX_N];
    int AperB[MAX_N];
    int AobB[MAX_N];
    int ArizB[MAX_N];
    int AxorB[MAX_N];

    cout << "Введіть кількість елементів універсуму (n): ";
    cin >> n;

    cout << "Введіть елементи універсуму U[" << n << "]: ";
    for (int i = 0; i < n; ++i) {
        cin >> U[i];
    }

    
    int ka;
    cout << "Введіть кількість елементів множини A: ";
    cin >> ka;


    cout << "Введіть елементи множини A[" << ka << "]: ";
    for (int i = 0; i < ka; ++i) {
        cin >> A[i];
    }


    int kb;
    cout << "Введіть кількість елементів множини B: ";
    cin >> kb;


    cout << "Введіть елементи множини B[" << kb << "]: ";
    for (int i = 0; i < kb; ++i) {
        cin >> B[i];
    }


    bubbleSort(U, n);


    for (int i = 0; i < n; ++i) {
        int r = 0;
        for (int j = 0; j < ka; ++j) {
            if (U[i] == A[j]) {
                r = 1;
                break;
            }
        }
        Abit[i] = r;
    }


    for (int i = 0; i < n; ++i) {
        int r = 0;
        for (int j = 0; j < kb; ++j) {
            if (U[i] == B[j]) {
                r = 1;
                break;
            }
        }
        Bbit[i] = r;
    }


    for (int i = 0; i < n; ++i) {
        notA[i] = 1 - Abit[i];
        AperB[i] = (Abit[i] == 1 && Bbit[i] == 1) ? 1 : 0;
        AobB[i] = (Abit[i] == 1 || Bbit[i] == 1) ? 1 : 0;
        ArizB[i] = (Abit[i] == 1 && Bbit[i] == 0) ? 1 : 0;
        AxorB[i] = (Abit[i] != Bbit[i]) ? 1 : 0;
    }

    cout << "\nУніверсум (відсортований): ";
    for (int i = 0; i < n; ++i) cout << U[i] << " ";

    cout << "\n\nБітовий рядок множини A:      ";
    for (int i = 0; i < n; ++i) cout << Abit[i];

    cout << "\nБітовий рядок множини B:      ";
    for (int i = 0; i < n; ++i) cout << Bbit[i];

    cout << "\nNOT A:                        ";
    for (int i = 0; i < n; ++i) cout << notA[i];

    cout << "\nA AND B (AперB):              ";
    for (int i = 0; i < n; ++i) cout << AperB[i];

    cout << "\nA OR B  (AобB):               ";
    for (int i = 0; i < n; ++i) cout << AobB[i];

    cout << "\nA \\ B   (AризB):              ";
    for (int i = 0; i < n; ++i) cout << ArizB[i];

    cout << "\nA XOR B (AxorB):              ";
    for (int i = 0; i < n; ++i) cout << AxorB[i];

    // 12. Кінець
    cout << "\n\nЗавершення програми." << endl;
   
    return 0;
}
