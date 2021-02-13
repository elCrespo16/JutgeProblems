#include <iostream>
#include <string>
using namespace std;
int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //intervalos iguales
    if (a == c and b == d) cout << "=";
    else if (a <= c and d <= b) cout << "2";
    else if (c <= a and b <= d) cout << "1";
    else  cout << "?";
    cout << endl;
    }