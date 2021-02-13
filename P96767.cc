#include <iostream>
#include <string>
using namespace std;

int main () {
    cout.setf(ios::fixed);
     cout.precision(4);
    double a, b, c, d = 1;
    cin >> b;
    while (cin >> a) {
	c = c + a * d;
	d = d * b;
    }
    cout << c << endl;
}