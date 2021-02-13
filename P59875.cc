#include <iostream>
#include <string>
using namespace std;

int main() {
    int x , y ,numero;
    cin >> x >> y;
    
    if (x > y) {
	numero = x;
	while (numero >= y){
	    cout << numero << endl;
	    --numero;
	}
    }
    else {
	numero = y;
	while (numero >= x) {
	    cout << numero << endl;
	    --numero;       
	}
    }
}