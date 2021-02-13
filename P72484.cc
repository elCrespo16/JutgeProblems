#include <iostream>
#include <string>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
	int es = n - 1, li = 0,as = 1;
	while (li < n) {
	    for (int a = 0;a < es; ++a) {
		cout << " ";
	    }
	    for (int s = 0;s < as; ++s) {
		cout << "*";
	    }
	    ++li;
	    --es;
	    as = as + 2;
	    cout << endl;
	}
	li = n - 1;
	es = 1;
	as = (n * 2) - 3;
	for (int a = 0;a < li; ++a) {
	    for (int s = 0; s < es; ++s){
		cout << " ";
	    }
	    for (int b = 0;b < as;++b){
		cout << "*";
	    }
	    ++es;
	    as = as - 2;
	    cout << endl;
	}
    }
}	    