#include <iostream>
#include <string>
using namespace std;
bool es_data_valida(int d, int m, int a){
    //dia mal
    if (d > 31 or d < 1) return false;
    //mes mal
    else if (m > 12 or m < 1) return false;
    //mes 31
    else if (d == 31 and (m == 2 or m == 4 or m == 6 or m == 9 or m == 11)) return false;
    else if (m == 2 and d == 30) return false;
    else if (m == 2 and d == 29) {
	if (a % 400 == 0 or (a % 4 == 0 and a%100 != 0)) return true;
	else return false;
	}
    else return true;
}

int main () {
    int a, m, d;
    while (cin >> d) {
	cin >> m >> a;
	if (es_data_valida(d, m, a) == 0) cout << "false" << endl;
	else cout << "true" << endl;
    }
}
    