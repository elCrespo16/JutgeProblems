#include <iostream>
#include <string>
using namespace std;
int main () {
    int h,m,s;
    cin >> s;
    if (s > 60){
	m = s / 60 ;
	s = s % 60 ;
	if (m > 60) {
	    h = m / 60;
	    m = m % 60;
	    cout << h << " " << m << " " << s << endl;
	}
	else if (m==60) {
	    cout << 1 << " " << 0 << " " << 0 << endl;
	}
	else {
	    cout << 0 << " " << m << " " << s << endl;
	}
    }
    else if (s==60){
	 cout << 0 << " " << 1 << " " << 0 << endl;  
	}
    else {
	    cout << 0 << " " << 0 << " " << s << endl;
	}
}
    