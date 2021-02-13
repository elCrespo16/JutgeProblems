#include <iostream>
using namespace std;
int suma_digits(int n){
    if (n / 10 == 0) return n;
 	return n % 10 + suma_digits(n / 10);
 }
 bool isPrime(long num) {
    if (num < 2) return false;
    if (num % 2 == 0) return false;
    for(int i = 3;i*i <= num;i += 2) {
		if ((num % i) == 0) return 0;
    }
    return true; 
}
 
bool es_primer_perfecte(int n){
    if (n < 10) {
        if(n == 2 or n == 3 or n == 5 or n == 7)return true;
 		return false;
    }	
    if (es_primer_perfecte(suma_digits(n)) and isPrime(n))return true;
 	return false;
}

int main () {
    int n;
    while (cin >> n) {
	cout << es_primer_perfecte(n) << endl;
    }
}