#include <iostream>
#include <string>
using namespace std;

void gira () {
    string n;
    if(not (cin >> n)) return;
    else {
	gira();
	cout << n << endl;
    }
}

int main () {
    gira();
}