#include <iostream>
#include <string>
using namespace std;

int main () {
    int b = 0, c = 0;
    char a;
    while (cin >> a) {
	if (a == 'n') --c;
	else if (a == 's') ++c;
	else if (a == 'e') ++b;
	else if (a == 'o') --b;
    }
    cout << "(" << b << ", " << c << ")" << endl;
}