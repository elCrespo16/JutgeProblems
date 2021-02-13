#include <iostream>
using namespace std;

//dice quien gana el enfrentamiento
int main () {
    char fi, se;
    cin >> fi >> se;
    if (fi == se) cout << "-" << endl;
    else if(fi == 'A') {
	if (se == 'P') cout << "1" << endl;
	else cout << "2" << endl;
    }
    else if(fi == 'P') {
	if (se == 'V') cout << "1" << endl;
	else cout << "2" << endl;
    }
    else if(fi == 'V') {
	if (se == 'A') cout << "1" << endl;
	else cout << "2" << endl;
    }
}