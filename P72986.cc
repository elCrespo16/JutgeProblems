#include <iostream>
#include <string>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);
    double a, b, d = 0;
    cin >> a;
    while (cin >> b) {
	d = b + a * d;
    }
    cout << d << endl;
}