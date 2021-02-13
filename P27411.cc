#include <iostream>

using namespace std;

int main () {
    int kon, a = 0,i = 0,num;
    cin >> kon;
    if (kon <= 0) {
	cout << "Posicio incorrecta." << endl;
	return 0;
    }
//     for(int i = 0;i < kon;++i){
// 	bool l (cin >> a);
// 	if(not l) {
// 	    cout << "Posicio incorrecta." << endl;
// 	    return 0;
// 	}
//     }
//     cout << "A la posicio " << kon << " hi ha un " << a << "." << endl;
// }
    while(cin >> a) {
	++i;
	if(kon == i)num = a;
    }
    if (i < kon or num == -1) cout << "Posicio incorrecta." << endl;
    else cout << "A la posicio " << kon << " hi ha un " << num << "." << endl;
}