#include <iostream>
#include <string>
using namespace std;

int main (){
    int a,b,c;
    cin >> a >> b >> c;
    if(a<b){
	if(b<=c){
	    cout << c << endl;
	}
	else if(b>=c) {
	    cout << b << endl;
	}
    }
    else if(a>c) {
	cout << a << endl;
    }
    else {
	cout << c << endl;
    }
}	