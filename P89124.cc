#include <iostream>
#include <vector>

using namespace std;

int main () {
    int a = 10000000, b;
    
    vector<bool> v = vector<bool>(a,false);
    v[1] = true;
    v[0] = true;
    for (int i = 2;i < a;++i) {
	if(v[i] == false) {
	    for (int o = i+i;o < a;o = o + i) {
		v[o] = true;
	    }
	}
    }
    while(cin >> b) {
	if (v[b] == false) cout << b << " es primer" << endl;
	else cout << b << " no es primer" << endl;
    }
}