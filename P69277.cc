#include <iostream>
#include <string>
using namespace std;
 int main () {
     int a, b, c;
     cin >> a;
     c = 1;
     cout << 0 ; 
     while (c <= a) {
	 b = c * c * c;
	 cout << "," << b;
	 ++c;
     }
     cout << endl;
 }