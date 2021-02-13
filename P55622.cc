#include <iostream>
#include <string>
using namespace std;

int main (){
    int a, b = 0;
    cin >> a;
    cout << "The number of digits of " << a;
    if (a == 0) b = 1;
    while (a != 0) {
	a = a / 10;
	++b;
    }
    cout <<" is " << b << "." << endl;
}