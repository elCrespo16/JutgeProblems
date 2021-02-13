#include <iostream>
#include <cmath>

using namespace std;
int main () {
    cout.setf(ios::fixed);
     cout.precision(6);
    double a, b;
    while (cin >> a) {
	b = sin (a * M_PI/180);
	cout << b << " ";
	b = cos (a * M_PI / 180);
	cout << b << endl;
    }
}