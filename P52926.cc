#include <iostream>
#include <string>
using namespace std;

void gira () {
    string n;
    if(cin >> n and n == "fi") return;
    else {
	gira();
	cout << n << endl;
    }
}

int main () {
    gira();
}