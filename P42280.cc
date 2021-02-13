#include <iostream>
#include <string>
using namespace std;
int main () {
    int files, columnes, monedes = 0;
    char a ;
    cin >> files >>columnes;
    for (int u = 0;u < files; ++u) {
	for (int i = 0;i < columnes; ++i) {
	    cin >> a;
	    monedes = monedes + (a - '0');
	}
    }
    cout << monedes << endl;
}