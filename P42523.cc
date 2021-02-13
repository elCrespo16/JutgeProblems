#include <iostream>

using namespace std;
int mcd (int a, int b) {
    if (a == b) return a;
    if (a == 0 or b == 0) return a+b;
    else {
	int x = mcd(a%b,b%a);
	return x;
    }
}

int main () {
    int a ,b;
    while (cin >> a >> b) {
	cout << mcd(a,b) << endl;
    }
}