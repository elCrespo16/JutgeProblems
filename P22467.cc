#include <iostream>
using namespace std;
int suma_digits(int n){
    if (n / 10 == 0) return n;
    else {
 	int i = suma_digits (n % 10);
 	return i + suma_digits(n / 10);
     }
 }
 bool isPrime(long num) {
    if (num < 2) return false;
    if (num > 2 and (num % 2) == 0) return false;
    for(int i = 2;i*i <= num;++i) {
	if ((num % i) == 0) return 0;
    }
    return true; 
}
 
 bool es_primer_perfecte(int n){
     int x = suma_digits(n); 
     if (x < 10) {
 	if(isPrime(x) and isPrime(n))return true;
 	else return false;
     }
     else {
	bool i = es_primer_perfecte(x);
 	if (i and isPrime(n))return true;
 	else return false;
      }
   }

int main () {
    int n;
    while (cin >> n) {
	cout << es_primer_perfecte(n) << endl;
    }
}