#include <iostream>
#include <string>
using namespace std;

int main () {
    int b = 0;
    char a;
    cin >> a;
    while (a != '.') {
	if (a == 'a') ++b;
	cin >> a;
    }
    cout << b << endl;
}
    