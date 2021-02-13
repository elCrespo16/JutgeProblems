#include <iostream>
#include <string>
using namespace std;
 int main () {
     int a ,b ,c ,r;
     cin >> a >> b;
     c=a/b;
     r=a%b;
     if (a<0) {
	 if (r==0){
	     cout << c << " " << r << endl;
	 }
	 else{
	 c=c-1;
	 r=-c*b+a;
	 cout << c << " " << r << endl;
	 }
     }
     else {
	 cout << c << " " << r << endl;
     }
 }