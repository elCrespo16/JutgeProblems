#include <iostream>
#include <string>
using namespace std;
int main () {
    cout.setf(ios::fixed);
     cout.precision(2);
    double a, b, c, d;
    while (cin >> a) {
	d = d + a; 
	++b;
    }
    c = d / b;
    cout << c << endl;
}