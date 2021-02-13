#include <iostream>
#include <string>

using namespace std;

struct Rational {
         int num, den;
     };
     
     
int mcd(int a, int b){
    if (b == 0) return a;
    return mcd(b, a%b);
}
Rational read_rational( int num, int den){
	Rational a;
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

void alu(Rational& res, const int& ope){
	int num2, den2;
	cin >> num2 >> den2;
	//suma
	if (ope == 1){
		int maxc = mcm(den2,res.den);
		res.num = res.num * (maxc/res.den) + num2 * (maxc/den2);
		res.den = maxc;
	}
	//resta
	else if (ope == 2) {
		int maxc = mcm(den2,res.den);
		res.num = res.num * (maxc/res.den) - num2 * (maxc/den2);
		res.den = maxc;
	}
	//multi
	else if (ope == 3) {
		res.num = res.num * num2;
		res.den = res.den * den2;
	}
	//divi
	else {
		res.num = res.num * den2;
		res.den = res.den * num2;
	}
}

int main () {
	int num, den;
	 Rational res;
	 string ope;
	 cin >> num >> den;
			 res.num = num;
			 res.den = den;
			 res = read_rational(res.num,res.den);
		if (res.num % res.den == 0)cout << res.num  / res.den;
		else cout << res.num << "/" << res.den;
		cout << endl;
	while (cin >> ope) {
			if (ope == "add" ) alu(res, 1);
			else if (ope == "substract") alu(res,2);
			else if (ope == "multiply")  alu(res,3);
			else alu(res,4);
		res = read_rational(res.num,res.den);
		if (res.num % res.den == 0)cout << res.num / res.den;
		else cout << res.num << "/" << res.den;
		cout << endl;
	}
}