#include <iostream>
#include <string>
using namespace std;
int main() {
    int a, b, c = 1, d;
    while (cin >> a and cin >> b) {
	d = a;
	while (c < b) {
	    a = a * d;
	    c = c + 1;
	}
	if (b == 0) cout << 1 << endl;
	else cout << a << endl;
	c = 1;
    }
}