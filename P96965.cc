#include <iostream>
using namespace std;
int suma_digits(int x){
    if (x / 10 == 0) return x;
    else {
	int i = suma_digits (x%10);
	return i + x / 10;
    }
}

 int reduccio_digits(int x){
     int n = suma_digits(x);
     if (n < 10) return n;
     else {
 	x = reduccio_digits(n);
	return x;
    }
 }

int main () {
    int x;
    while (cin >> x) {
	cout << reduccio_digits(x) << endl;
    }
}