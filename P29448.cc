#include <iostream>
#include <string>
using namespace std;
int main() {
    int any, mes , dia;
    while (cin >> dia) {
	cin >> mes >> any;
	//dia mal
	if (dia > 31 or dia < 1) cout << "Data Incorrecta" << endl;
	//mes mal
	else if (mes > 12 or mes < 1) cout << "Data Incorrecta" << endl;
	//mes 31
	else if (dia == 31 and (mes == 2 or mes == 4 or mes == 6 or mes == 9 or mes == 11)) {
	    cout << "Data Incorrecta" << endl;
	}
	else if (mes == 2 and dia == 30) cout << "Data Incorrecta" << endl;
	else if (mes == 2 and dia == 29) {
	    if (any%400 == 0 or (any%4 == 0 and any%100 != 0)) cout << "Data Correcta" << endl;
	    else cout << "Data Incorrecta" << endl;
	}
	else cout << "Data Correcta" << endl;
    }
}