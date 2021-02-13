#include <iostream>
#include <string>
using namespace std;
int main () {
    string g;
    int i = 0;
    bool fi = 1,pr = 0;
    while(cin >> g and fi) {
	if(g == "principi")pr = 1;
	else if(g == "final")fi = 0;
	else if(pr)++i;
    }
    if(fi or not pr)cout << "sequencia incorrecta" << endl;
    else cout << i << endl;
}