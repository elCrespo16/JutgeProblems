#include <iostream>

using namespace std;


bool isPrime(int num) {
    if (num < 2) return false;
    if (num > 2 and (num % 2) == 0) return false;
    for(int i = 2;i*i <= num;++i) {
	if ((num % i) == 0) return false;
    }
    return true;
}

int main () {
    int a;
    bool b = 0;
    while(not b) {
	cin >> a;
	if (not isPrime(a)) b = 1;
	else {
	    int b;
	    b = ++a;
	    while(not isPrime(b))++b;
	    cout << b << endl;
	}
    }
}