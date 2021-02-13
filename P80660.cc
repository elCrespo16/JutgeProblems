#include <iostream>
#include <string>
using namespace std;

int main () {
    int a, b = 0;
    while (cin >> a) { 
	if (a > 1) {
	    while (a != 1) {
		if (a % 2 == 0) {
		    a = a / 2;
		    ++b;
		}
		else {
		    a = a * 3 + 1;
		    ++b;
		}
	    }
	    cout << b << endl;
	}
	else {
	    cout << 0 << endl;
	}
	b = 0;
    }
}