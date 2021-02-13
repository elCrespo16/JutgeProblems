#include <iostream>
#include <string>

using namespace std;

int main () {
    int a = 1,b = 0;
    string h, g;
    cin >> h;
    while (cin >> g) {
	if(g == h){
	    ++a;
	}
	else {
	    if(a != 0 and a > b) b = a;
	    a = 0;
	}
    }
    if (a >= b)cout << a << endl;
    else cout << b << endl;
}