#include <iostream>
using namespace std;
void asteriscos(int n) {
    if (n == 1)  {
	cout << "*";
	return;
    }
    else {
	asteriscos(n - 1);
	cout << endl;
	for(int i = 1;i <= n;++i) cout << "*";
	cout << endl;
	asteriscos(n - 1);
    }
}

int main() {
    int n;
    while (cin >> n) {
	asteriscos(n);
	cout << endl;
    }
}