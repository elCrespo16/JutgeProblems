#include <iostream>
#include <cmath>

using namespace std;
int main () {
    cout.setf(ios::fixed);
     cout.precision(6);
    int a;
    double b;
    while (cin >> a) {
	cout << a * a << " ";
	b = sqrt (a);
	cout << b << endl;
    }
}