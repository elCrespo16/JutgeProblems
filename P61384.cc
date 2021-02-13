#include <iostream>

using namespace std;
int double_factorial (int n) {
    if (n == 0 or n ==1) return 1;
    else {
	int x = double_factorial(n-2);
	return x*n;
    }
}

int main () {
    int n;
    while (cin >> n) {
	cout << double_factorial(n) << endl;
    }
}