#include <iostream>
#include <iostream>
using namespace std;
 int main() {
     cout.setf(ios::fixed);
     cout.precision(10);
    int n , m , nv , mv;
    while (cin >> n >> m) {
	double c = 0, d = 0 , e;
	mv = m;
	nv = n;
	    while (nv > mv) {
	    c = c + 1.0 / nv;
	    --nv;
	    }
	 cout << c << endl;
    }
}