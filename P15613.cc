#include <iostream>
#include <string>
using namespace std;

int main () {
    int t;
    cin >> t;
    if (t < 10) {
	cout << "fa fred" << endl;
	if(t<=0){
	    cout << "l'aigua es gelaria" << endl;
	}

    }
    else if (t <= 30) {
	if (t >= 10) {
	    cout << "s'esta be" << endl;
	}
    }
    else {
	cout << "fa calor" << endl;
	if(t>=100) {
	    cout << "l'aigua bulliria" << endl;
	}
    }
}