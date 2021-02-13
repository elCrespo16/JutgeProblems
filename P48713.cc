#include <iostream>

using namespace std;


bool isPrime(int num) {
    if (num < 2) return false;
    if (num > 2 and (num % 2) == 0) return false;
    for(int i = 2;i*i <= num;++i) {
	if ((num % i) == 0) return false;
    }
    return true;
}
int main () {
    int n, a;
    cin >> n;
    for(int i = 0;i < n;++i) {
	cin >> a;
	if(isPrime(a))cout << a << " es primer" << endl;
	else cout << a << " no es primer" << endl;
    }
}