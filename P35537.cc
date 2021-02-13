#include <iostream>
using namespace std;

bool es_creixent (int n) {
    if (n >= 0 and n < 10) return true;
    else {
//me guardo el ultimo numero
	int a = n % 10;
//actualizo todo para pillar el anterior a "a"
	int w = n / 10;
//pillo el anterior a "a"
	int p = w % 10;
//esto contiene si el resto de la cadena es tru o false
	bool c = es_creixent(w);
//esto me dice si el final es true o false (lo del iesimo)
	bool b = a >= p;
//si anteriores false entonces return false
	if (b and c) return true;
	else return false;    
    }
}

int main () {
    int n;
    while (cin >> n) {
	cout << es_creixent(n) << endl;
    }
}