#include <iostream>
#include <string>
using namespace std;

int main () {
    int a;
    bool primero = true;
    while (cin >> a)  {
	if (primero) primero = false;
	else cout << endl;
	for (int lineas = 0; lineas < a; ++lineas) {
	    for (int c = 0; c < a; ++c) {
		cout << a;
	    }
	    cout << endl;
	}
    }
}