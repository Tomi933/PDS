#include <iostream>
#include <Windows.h>
using namespace std;


void printPerm(int a[], int n) {
    for (int i = 0; i < n; i++) 
        cout << a[i];
    cout << "\n";
}

int firstNum(int a[], int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        m += a[i];
    }
    return m;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   /* int n;
    cout << "¬вед≥ть n: ";
    cin >> n;

    int a[20];
    firstNum(a, n);

    
    printPerm(a, n);

  
    while (true) {
       
        int j = n - 2;

        while (j >= 0 && a[j] >= a[j + 1]) 
            j--;

        if (j < 0) 
            break; 

       
        int k = n - 1;
        while (a[k] <= a[j]) 
            k--;

        
        int temp = a[j];
        a[j] = a[k];
        a[k] = temp;

        
        int l = j + 1, r = n - 1;
        while (l < r) {
            int t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }

        
        printPerm(a, n);
    }*/

    int n, r;
    cout << "¬вед≥ть n: ";
    cin >> n;
    cout << "¬вед≥ть r (r <= n): ";
    cin >> r;

    if (r > n || n <= 0 || r < 0) {
        cout << "Ќекоректн≥ дан≥!";
        return 0;
    }

    int a[100];
    firstNum(a, n);

    for (int i = 0; i < r; i++)
        cout << a[i];
    cout << endl;

    while (true) {
        int i = r - 1;

        while (i >= 0 && a[i] == n - r + i + 1)
            i--;

        if (i < 0) break; 

        a[i]++;

        for (int j = i + 1; j < r; j++)
            a[j] = a[j - 1] + 1;

        printPerm(a, r);
    }

    return 0;
}
