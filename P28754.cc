#include <iostream>
#include <string>
using namespace std;

int main (){
    int a, b;
    cin >> a;
    if (a == 0) cout << 0;
    while (a != 0) {
	cout << a % 2;
	a = a / 2;
    }
    cout << endl;
}