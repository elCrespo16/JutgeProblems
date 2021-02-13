#include <iostream>
#include <string>
using namespace std;

int main (){
    int a, b;
    cin >> a;
    while (a >= 16) {
	b = a % 16;
	if (b == 10) cout << "A";
	if (b == 11) cout << "B";
	if (b == 12) cout << "C";
	if (b == 13) cout << "D";
	if (b == 14) cout << "E";
	if (b == 15) cout << "F";
	if (b == 16) cout << "01";
	else if (b > 16 or b < 10) cout << b;
	a = a / 16;
    } 
	if (a == 10) cout << "A";
	if (a == 11) cout << "B";
	if (a == 12) cout << "C";
	if (a == 13) cout << "D";
	if (a == 14) cout << "E";
	if (a == 15) cout << "F";
	if (a == 16) cout << "01";
	else if (a > 16 or a < 10) cout << a;
    cout << endl;
}