#include <iostream>
using namespace std;

int mcd4(int a, int b, int c, int d) {
    int mayor1, mayor2;
    while (a != 0 and b != 0) {
	if (a > b) a = a % b;
	    else b = b % a;
	}
    mayor1 = a + b;
    while (c != 0 and d != 0) {
	if (c > d) c = c % d;
	else d = d % c;
    }
    mayor2 = c + d;
    while (mayor1 != 0 and mayor2 != 0) {
	if (mayor1 > mayor2) mayor1 = mayor1 % mayor2;
	else mayor2 = mayor2 % mayor1;
    }
    return mayor1 + mayor2;
}

int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
	cout << mcd4(a, b, c, d) << endl;
    }
}