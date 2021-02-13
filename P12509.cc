#include <iostream>

using namespace std;
int factorial (int n) {
    if (n == 0 or n ==1) return 1;
    else {
	int x = factorial(n-1);
	return x*n;
    }
}

int main () {
    int n;
    while (cin >> n) {
	cout << factorial(n) << endl;
    }
}