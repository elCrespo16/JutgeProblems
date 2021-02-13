#include <iostream>
#include <string>
using namespace std;
int main() {
    int a;
    while (cin >> a) {
	a = a / 5;
	a = a - 9;
	a = a / 4;
	a = a - 6;
	a = a / 5;
	cout << a << endl;
    }
}