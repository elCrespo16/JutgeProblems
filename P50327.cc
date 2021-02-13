#include <iostream>
#include <string>
using namespace std;
    int main () {
	int a, b;
	cin >> a;
	if (a == 0) cout << 0;
	while (a != 0) {
	    b = a % 10;
	    a = a / 10;
	    if (b < 0) cout <<b * -1;
	    else cout << b;
	}
	cout << endl;
    }