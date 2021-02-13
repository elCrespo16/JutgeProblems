#include <iostream>
using namespace std;

int suma_divisors(int a){
    int suma = 0;
    for(int i = 2;i*i <= a;++i) {
	if(a % i == 0) {
	    if(a / i == i)suma = suma + i;
	    else {
		suma = suma + i;
		suma = suma + a / i;
	    }
	}
    }
    return 1 + suma;
}

bool son_amics (int a,int b) {
    int sumb = 0,suma = 0;
    if(a == b)return false;
    suma = suma_divisors(a);
    sumb = suma_divisors(b);
    if(sumb == a and suma == b)return true;
    else return false;
}

int main () {
    int a, b;
    bool pri = true;
    while(cin >> a >> b) {
	if(son_amics(a,b)){
	    if(pri) pri = false;
	    else cout << ",";
	    cout << "(" << a << " " << b << ")";
	}
    }
    cout << endl;

}