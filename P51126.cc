#include <iostream>
#include <string>
using namespace std;
int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //C y D dentro de A y B 
    if (a < c and b > d) cout << "[" << c  << "," << d << "]" << endl;
    
    //solo una parte de A esta dentro 
    else if (a > c and b < d and c < b) cout << "[" << a << "," << b << "]" << endl;
    //solo una parte de A esta dentro
    else if (a > c and b > d and a < d) cout << "[" << a << "," << d << "]" << endl;
    //A y B dentro de C y D
    else if (a > c and b < d) {
	cout << "[" << a << "," << b << "]" << endl;
    }
    //Son iguales
    else if (a==c and b==d) {
	cout << "[" << a << ","  << b << "]" << endl;
    }
    else if (a==d) cout << "[" << a << ","  << d << "]" << endl;
    
    else if (b==c) cout << "[" << c << ","  << b << "]" << endl;
    
    else if (a < c and b < d and c < b) cout << "[" << c << ","  << b << "]" << endl;
    
    else if (a == c){
	if (b < d) cout << "[" << a << ","  << b << "]" << endl;
	else cout << "[" << a << ","  << d << "]" << endl;
    }
    else if (b == d) {
	if (a<c) cout << "[" << c << ","  << d << "]" << endl;
	else cout << "[" << a << ","  << d << "]" << endl;
    }
    else cout << "[" << "]" << endl;
}