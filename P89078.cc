#include <iostream>

using namespace std;

int main () {
    int a, cont = 0;
    while (cin >> a) {
	++cont;
	if (a % 2 == 0) {
	    cout << cont << endl;
	    return 0;
	}
    }
}