#include <iostream>
#include <string>
using namespace std;
 int main () {
     int a, b, c;
     cin >> a;
     b = 1;
     c = 1;
     while (c <= 10) {
	 b = a * c;
	 cout << a << "*" << c << " " << "=" << " " << b << endl;
	 ++c;
     }
 }