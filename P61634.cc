#include <iostream>
#include <string>
using namespace std;
int main() {
    int any, res, tu;
    cin >> any;
    /*if (any % 4 > 0) {
	cout << "NO" << endl;
    }
    else {
	if (any % 100 > 0) {
	    cout << "YES" << endl;
	}
	else {
	    if ((any / 100) % 4 > 0) {
		cout << "NO" << endl;
	    }
	    else {
	    cout << "YES" << endl;
	    }
	}
    }*/
    if (any%400 == 0 or (any%4 == 0 and any%100 != 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
}