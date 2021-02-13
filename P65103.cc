#include <iostream>

using namespace std;

int main () {
    int kon, a = 0,i = 0,num;
    cin >> kon;
    if (kon <= 0) {
	cout << "Posicio incorrecta." << endl;
	return 0;
    }
    while(cin >> a) {
	++i;
	if(kon == i)num = a;
    }
    if (i < kon) cout << "Posicio incorrecta." << endl;
    else cout << "A la posicio " << kon << " hi ha un " << num << "." << endl;
}