#include <iostream>
#include <string>
using namespace std;

void gira (int& a) {
    string n;
    if (cin >> n) {
	gira(a);
	if(a > 0) {
	    cout << n << endl;
	    --a;
	}
    }
}

int main () {
    int a;
    cin >> a;
    gira(a);
}