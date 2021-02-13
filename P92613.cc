#include <iostream>
#include <string>
using namespace std;

int main () {
    double  c , d;
    cin >> c;
    d=c-int(c);
    if (d>0){
	cout << int(c) << " " << int(c)+1 << " ";
	if (d>=0.5) {
	    cout << int(c)+1 << endl;
	}
	else {
	    cout << int(c) << endl;
	}
    }
    else if (d==0) {
	cout << int(c) << " " << int(c) << " " << int(c) << endl;
    }
}