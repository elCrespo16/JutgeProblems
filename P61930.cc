#include <iostream>
using namespace std;
int suma_digits(int n){
    if (n / 10 == 0) return n;
    else {
	int i = suma_digits (n % 10);
	return i + n / 10;
    }
}

bool es_multiple_3(int n){
     int x = suma_digits(n);
     if (x % 3 == 0) return true;
     else return false;
 }

int main () {
    int n;
    while (cin >> n) {
	if (es_multiple_3(n)) cout << "true" << endl;
	else cout << "false" << endl;
    }
}