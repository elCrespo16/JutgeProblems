#include <iostream>
#include <string>
using namespace std;
int main () {
    int fila, colum, monedes = 0;
    char juntas;
    cin >> fila;
    colum = fila;
    for (int ila = 0; ila < fila; ++ila) {
	for (int olum = 0;olum < colum;++olum) {
	    cin >> juntas;
	    if (ila == olum or (ila + olum) == (fila - 1)) {
		monedes = monedes + (juntas - '0');
	    }
	}
    }
    cout << monedes << endl;
}