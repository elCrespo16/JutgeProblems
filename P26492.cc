#include <iostream>

using namespace std;

int number_of_digits (int n) {
    if (n / 10 == 0) return 1;
    else {
	int x = number_of_digits(n/10);
	return x+1;
    }
}

bool es_equilibrat(int n) {
    int par = 0, im = 0;
    int x = number_of_digits(n);
    for(int i = 1;i <= x;++i){
	if(i % 2 == 0)par = par + (n % 10);
	else im = im + (n % 10);
	n = n / 10;
    }
    if(im == par) return true;
    else return false;
}

int main () {
    int a;
    while(cin >> a) {
	cout << es_equilibrat(a) << endl;
    }
}