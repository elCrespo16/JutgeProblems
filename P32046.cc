#include <iostream>
using namespace std;

//dice los numeros que acaban en lo mismo
int main () {
    int f1, f2, total = 0, jj, jk;
    cin >> f1;
    jj = f1 % 1000;
    cout << "nombres que acaben igual que " << f1 << ":" << endl;
    while (cin >> f2) {
        jk = f2 % 1000;
        if(jk == jj) {
            cout << f2 << endl;
            ++total;
        }
    }
    cout << "total: " << total << endl;
}
