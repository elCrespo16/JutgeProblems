#include <iostream>

using namespace std;

int number_of_digits (int n) {
    if (n / 10 == 0) return 1;
    else {
	int x = number_of_digits(n/10);
	return x+1;
    }
}


int central(int val, int ndi) {
    for(int i = 0;i < (ndi/2);++i){
	val = val / 10;
    }
    return val % 10;
}


int main () {
    int n, val, ndi, cent = 0, i;
    bool a = true;
    cin >> n;
	for(i = 0;i < n*2 and a;++i) {
        cin >> val;
        ndi = number_of_digits(val);
        if(ndi % 2 == 0)a = false;
        if(i == 0)cent = central(val,ndi);
        if(central(val,ndi) != cent)a = false;
    }
    if(a) cout << "=" << endl;
    if(not a) {
        if(i % 2 == 0)cout << "A" << endl;
        else cout << "B" << endl;
    }
    
}
