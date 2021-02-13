#include <iostream>
using namespace std;

int mcd(int a, int b){
    if (b == 0) return a;
    else if (a == 0) return b;
    else {
	while (a != 0 and b != 0) {
	    if (a > b) a = a % b;
	    else b = b % a;
	}
	return a+b;
    }
}
int main () {
    int a, b;
    while (cin >> a >> b){
	cout << mcd (a,b) << endl;
	
    }
}   