#include <iostream>

using namespace std;

void posicion(int n){
    int b, i = 1;
    bool si = true, palabra = true;
    while (si) {
	cin >> b;
	if(b == -1){
	    si = false;
	}
	else if(n == i){
	    cout << "A la posicio " << n << " hi ha un " << b << "." << endl;
	    palabra = false;
	}
	++i;
    }
    if(palabra)cout << "Posicio incorrecta." << endl; 
}

int main () {
    int n;
    while(cin >> n) {
	posicion(n);
    }
}