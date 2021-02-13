#include <iostream>

using namespace std;

struct Clock {
         int h;      // hours (0<=h<24)
         int m;      // minutes (0<=m<60)
         int s;      // seconds (0<=s<60)
     };

Clock midnight(){
    Clock lul;
    lul.h = lul.m = lul.s = 0;
    return lul;
}
void increase(Clock& r){
    r.s = r.s + 1 ;
    if (r.s == 60) {
	r.m = r.m + 1;
	r.s = 0;
	if (r.m == 60) {
	    r.h = r.h + 1;
	    r.m = 0;
	    if (r.h == 24) r.h = 0;
	}
    }
}
void print(const Clock& r){
    if(r.h >= 10)cout << r.h << ":";
    else cout << "0" << r.h << ":";
    if(r.m >= 10)cout << r.m << ":";
    else cout << "0" << r.m << ":";
    if(r.s >= 10)cout << r.s << endl;
    else cout << "0" << r.s << endl;
}