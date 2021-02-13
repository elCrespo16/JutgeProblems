#include <iostream>
using namespace std;

void hexa (int n) {
    if(n == 0 )return;
    hexa(n / 16);
    int b;
    b = n % 16;
    if (b == 10) cout << "A";
    if (b == 11) cout << "B";
    if (b == 12) cout << "C";
    if (b == 13) cout << "D";
    if (b == 14) cout << "E";
    if (b == 15) cout << "F";
    if (b == 16) cout << "01";
    else if (b > 16 or b < 10) cout << b;
}

void octal (int n) {
   if(n == 0)return;
   octal(n / 8);
   cout << n % 8;
}

void bin(int n ) {
   if(n == 0 )return;
   bin(n / 2);
   cout << n % 2;
}

int main () {
    int n;
    while (cin >> n) {
	cout << n << " = ";
	bin(n);
	if(n == 0) cout << 0;
	cout << ", ";
	octal(n);
	if(n == 0) cout << 0;
	cout << ", ";
	hexa(n);
	if(n == 0) cout << 0;
	cout << endl;
    }
}