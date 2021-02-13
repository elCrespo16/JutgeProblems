#include <iostream>
#include <string>
using namespace std;
int main () {
    int h, min, sec;
    cin >> h >> min >> sec;
    sec = sec + 1 ;
    if (sec == 60) {
	min = min + 1;
	sec = 0;
	if (min == 60) {
	    h = h + 1;
	    min = 0;
	    if (h == 24) h = 0;
	}
    }
    if (h < 10) cout << "0";
    cout << h << ":";
    if (min < 10) cout << "0";
    cout << min << ":";
    if (sec < 10) cout << "0";
    cout << sec << endl;
}	    