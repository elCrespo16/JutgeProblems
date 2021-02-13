#include <iostream>
#include <string>
using namespace std;

int main () {
    int a, b = 0;
    while (cin >> a) {
	string j;
	while (b < a){
	    j = j + "*";
	    ++b;
	    cout << j << endl;
	}
	b = 0;
    }
}