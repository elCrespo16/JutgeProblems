#include <iostream>
using namespace std;

int nxifres(int n){
    int b = 0;
    if (n == 0) return 1;
    while (n != 0) {
	n = n / 10;
	++b;
    }
    return b;
}
int elevate (int n) {
    int a = 1;
    for (int i = 0;i < n;++i){
	a = a * 10;
    }
    return a;
}

int main () {
    int n, rot;
    while(cin >> n >> rot){
	if(rot == 0)  cout << n << endl;
	else {
	    int a = nxifres(n), ot = 0;
	    int el = elevate(rot);
	    ot = n % el;
	    n = n / el;
	    el = elevate(a-rot);
	    n = n + (ot*el);
	    cout << n << endl;
	}    
    }
}