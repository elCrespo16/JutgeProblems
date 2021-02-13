#include <iostream>

using namespace std;

struct Fraction {
         int num, den;
     };
     
     
int mcd(int a, int b){
    if (b == 0) return a;
    return mcd(b, a%b);
}
Fraction read_rational(int num, int den){
	Fraction a;
	if (num == 0) {
		a.num = 0;
		a.den = 1;
		return a;
	}
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

int mcm (const int& a, const int& b){
	return a * b / mcd (a,b);
}


Fraction addition(const Fraction& x, const Fraction& y){
    Fraction res;
    int maxc = mcm(x.den,y.den);
	res.num = x.num * (maxc/x.den) + y.num * (maxc/y.den);
	res.den = maxc;
    return read_rational(res.num,res.den);
}

int main () {
    char a;
    Fraction x, y;
    bool b = true;
    cin >> x.num >> a >> x.den;
    while(b and cin >> a){
        if(a == '=')b = false;
        else {
            cin >> y.num >> a >> y.den;
            x = addition(x,y);
        }
    }
    cout << x.num << "/" << x.den << endl;
}