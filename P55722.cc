#include <iostream>
using namespace std;


int nombre_digits(int n){
    int b = 0;
    if (n == 0) {
	++b;
    }
    while (n > 0) {
	    ++b;
	    n = n / 10;
	}
    return b;
}
int main () { 
    int n;
    while (cin >> n) cout << nombre_digits(n) << endl;
}