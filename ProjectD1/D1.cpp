#include <iostream>
#include <Windows.h>
using namespace std;

//bool Conjunction(bool a, bool b)
//{
//    return a && b;
//}

string Update(string y, string a, string b, int n)
{
    for (int i = 0; i < n; ++i) {
        char ai = a[i];
        char bi = b[i];
        char c;

        if (ai == '1' && bi == '1')
            c = '1';
        else
            c = '0';
        y += c;
    }
    return y;
}


int main() {
    SetConsoleCP(1251);          
    SetConsoleOutputCP(1251);

    //bool p = true;   
    //bool q = false;

    //

    //bool conjunction = Conjunction(p, q);           // Кон’юнкція
    //bool disjunction = p || q;           // Диз’юнкція
    //bool exclusive_or = p != q;          // Альтернативне АБО (XOR)
    //bool implication1 = (!p) || q;        // Імплікація
    //bool implication2 = p || (!q);        // Імплікація
    //bool equivalence = implication1 && implication2;           // Еквівалентність

    //
    //cout << boolalpha; 
    //cout << "p = " << p << endl;
    //cout << "q = " << q << endl;
    //cout << "Кон’юнкція (p && q): " << conjunction << endl;
    //cout << "Диз’юнкція (p || q): " << disjunction << endl;
    //cout << "Альтернативне АБО (p XOR q): " << exclusive_or << endl;
    //cout << "Імплікація (p -> q): " << implication1 << endl;
    //cout << "Імплікація (q -> p): " << implication2 << endl;
    //cout << "Еквівалентність (p = q): " << equivalence << endl;


    string a, b;
    a = "111100000";
    b = "101010011";

    int n = a.length();

    string x = "", y = "", z = "";

    for (int i = 0; i < n; ++i) {
        char ai = a[i];
        char bi = b[i];
        char c;

        // 5.1) OR
        if (ai == '1' && bi == '1')
            c = '1';
        else if (ai == '1' && bi == '0')
            c = '1';
        else if (ai == '0' && bi == '1')
            c = '1';
        else
            c = '0';
        x += c;

        

        // 5.5) XOR
        if ((ai == '1' && bi == '0') || (ai == '0' && bi == '1'))
            c = '1';
        else
            c = '0';
        z += c;
    }

    // 5.3) AND
    

    cout << "\nРезультати:\n";
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "OR  (x): " << x << endl;
    cout << "AND (y): " << Update(y, a, b, n) << endl;
    cout << "XOR (z): " << z << endl;

    return 0;
}
