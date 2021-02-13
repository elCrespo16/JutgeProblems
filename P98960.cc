#include <iostream>
#include <string>
using namespace std;
int main() {
    char a;
    int c;
    cin >> a;
    if (a >= 'a' and a <= 'z') {
	a = a - 'a';
	a = a + 'A';  
	cout << a << endl;
    }
    else {
	a = a - 'A';
	a = a + 'a';
	cout << a << endl;
    }
}