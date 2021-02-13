#include <iostream>
#include <string>
using namespace std;

int sum_divisors(int x){
    int s = 0;
    for (int i = 1;i*i<= x;++i) {
	if (x % i == 0) {
	    s = s + i;
	    if (i != x/i) s += x/i;
	}
    }
    return s;
}
int main () {
     int x;
    while (cin >> x ) cout << sum_divisors(x) << endl;
}