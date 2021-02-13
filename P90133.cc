#include <iostream>
using namespace std;

int main () {
    int a, b, c = 0;
    while (cin >> a) {
	cin >> b;
	while (b != 0) {
	    ++c;
	    b = b / a;
	    
	}
	cout << c - 1 << endl;
	c = 0;
    }
}