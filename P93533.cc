#include <iostream>
using namespace std;

void base (int n) {
    if (n == 0) return;
    else {
	int res = n % -2;
	int newN = n/-2;
	if (res < 0) {
	    res += 2;
	    newN += 1;
	}
	base(newN);
	cout << res;
    }
}

int main() {
    int n;
    while (cin >> n) {
	cout << n << ": ";
	base(n);
	if (n == 0) cout << 0;
	cout << endl;
    }
}