#include <iostream>

using namespace std;

struct Rational {
         int num, den;
     };
     
     
int mcd(int a, int b){
    if (b == 0) return a;
    return mcd(b, a%b);
}
Rational read_rational(int& num, int& den){
	Rational a;
    int gcd = mcd(num,den);
    num = num / gcd;
    den = den / gcd;
    if (den < 0){
    	den = den *  -1;
    	num = num * -1;
    }
    a.num = num;
    a.den = den;
    return a;
}

Rational rational(int n, int d){
	Rational a;
	if (n == 0) {
		a.num = 0;
		a.den = 1;
	}
	else a = read_rational(n,d);
	return a;
}

int main () {
	int num, den;
	while (cin >> num >> den) {
		cout << rational(num,den).num << rational(num,den).den << endl;
	}
}