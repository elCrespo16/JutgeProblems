#include <iostream>

using namespace std;

int main () {
    int kon, a = 0;
    cin >> kon;
    for(int i = 0;i < kon;++i){
	cin >> a;
    }
    cout << "A la posicio " << kon << " hi ha un " << a << "." << endl;
}