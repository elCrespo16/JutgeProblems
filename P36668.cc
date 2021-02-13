#include <iostream>
#include <string>
using namespace std;
 int main () {
     int a, b, c;
     cin >> a;
     b = 0;
     c = 0;
     while (b <= a) {
	 c = c + b * b ;
	 ++b; 
     }
     cout << c << endl;
 }