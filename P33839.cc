#include <iostream>
using namespace std;

int main () {
    int a , b = 0;
    while (cin >> a) {
	cout << "The sum of the digits of " << a << " is ";
	while (a != 0) {
	    b = a % 10 + b;
	    a = a / 10;
	}
	cout << b << "." << endl;
	b = 0;
    }
}