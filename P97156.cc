#include <iostream>
#include <string>
using namespace std;
 int main () {
     int a, b ,c;
     cin >> a >> b;
     if (a > b) cout << endl;
     else {
	 c = a;
	 cout << c;
	 while (c < b){
	    ++c;
	    cout << "," << c;
	 }
	 cout << endl;
     }
 }