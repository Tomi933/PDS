#include <iostream>
#include <iomanip>  
#include <Windows.h>
using namespace std;

bool EquivalenceTable(){

    bool p;
    bool q;
    int i = 0;
    bool implication1;
    bool implication2;
    bool equivalence;

    cout << boolalpha << endl;
    cout << left
        << setw(6) << "   p   |"
        << setw(6) << "   q   |"
        << setw(6) << " p = q |" << endl;

    cout << "------------------------" << endl;

  
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            p = i;
            q = j;

            implication1 = (!p) || q;    
            implication2 = (!q) || p;    
            equivalence = implication1 && implication2; 

         
            cout << left
                << setw(6) << p
                << " |" << setw(6) << q
                << " |" << setw(6) << equivalence << " |" << endl;
        }
    }

    return equivalence;
}




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    EquivalenceTable();

    return 0;
}