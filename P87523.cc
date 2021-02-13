#include <iostream>

using namespace std;

bool hola(char h){
    char o = 'i',l = 'i',a ='i';
    if(h == 'h'){
	cin >> o;
	if(o == 'h')if(hola(o))return true;
	if(o == 'o'){
	    cin >> l;
	    if(l == 'h')if(hola(l))return true;
	    if(l == 'l'){
		cin >> a;
		if(a == 'h')if(hola(a))return true;
		if(a == 'a'){
		    return true;
		}
	    }
	}
    }
    return false;
}
int main () {
    char h;
    bool no = 1,hi = 0;
    while (cin >> h and no and not hi) {
	if(h == '.')no = 0;
	else if(hola(h)){
	    hi = 1;
	    no = 0;
	}
    }
    if(hi == 1)cout << "hola" << endl;
    else cout << "adeu" << endl;
}