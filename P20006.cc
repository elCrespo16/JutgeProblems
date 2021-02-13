#include <iostream>

using namespace std;

int prefixed_expresion (){
    char n;
    cin >> n;
    if (n >= '0' and n <= '9') return n - '0';
    if (n == '+') return prefixed_expresion() + prefixed_expresion();
    if (n == '*') return prefixed_expresion() * prefixed_expresion();
    if (n == '-') return prefixed_expresion() - prefixed_expresion();
    return 0;
}

int main() {
    cout << prefixed_expresion() << endl;
}
