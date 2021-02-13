#include <iostream>
#include <string>
using namespace std;

void gira (int& a) {
    string n;
    if (not (cin >> n)) {
	if (a % 2 == 0) a = a / 2;
	else {
	    ++a;
	    a = a / 2;
	}
    }
    else {
	++a;
	gira(a);
	if(a > 0) {
	    --a;
	}
	else cout << n << endl;
    }
}

int main () {
    int a = 0;
    gira(a);
}