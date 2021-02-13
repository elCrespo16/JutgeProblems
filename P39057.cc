#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main () {
    cout.setf(ios::fixed);
     cout.precision(6);
     int a, d = 0;
     double b, c, e;
     string quadrado;
     cin >> a;
     while (d < a) {
	cin >> quadrado;
	 if (quadrado == "cercle") {
	    cin >> b;
	    e = b * b * M_PI;
	    cout << e << endl;
	}
	else {
	 cin >> b >> c;
	 e = b * c;
	 cout << e << endl;
	}
	++d;
     }
} 