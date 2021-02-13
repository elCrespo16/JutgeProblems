#include <iostream>
#include <string>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    cout << "El mcd de " << a << " i " << b << " es ";
    while (a > b or b > a) {
	if (a > b) a = a - b;
	else b = b - a;   
    }
    cout << b << "." << endl;
}