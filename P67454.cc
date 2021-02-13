#include <iostream>

using namespace std;

int main () {
    int i = 0;
    char a;
    bool s = 1;
    while (cin >> a and s) {
	if(a == 'a')++i;
	if(a == '.')s = 0;
    }
    cout << i << endl;
}