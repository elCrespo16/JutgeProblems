#include <iostream>
#include <string>
using namespace std;
bool es_any_de_traspas(int any) {
    int res, tu;
    if (any%400 == 0 or (any%4 == 0 and any%100 != 0)) return true;
    else return false;
}

int main () {
    int any;
    while(cin >> any) {
	if (es_any_de_traspas(any) == 0) cout << "false" << endl;
	else cout << "true" << endl;
    }
}