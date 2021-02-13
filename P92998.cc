#include <iostream>
#include <string>
using namespace std;

void gira (int a) {
    string n;
    cin >> n;
    if(a == 0) return;
    else {
	gira(--a);
	cout << n << endl;
    }
}

int main () {
    int a;
    cin >> a;
    gira(a);
}