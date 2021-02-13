#include <iostream>

using namespace std;

int mcd(int a, int b){
    if (b == 0) return a;
    return mcd(b, a%b);
}
void read_rational(int& num, int& den){
    char m;
    cin >> num >> m >> den;
    int gcd = mcd(num,den);
    num = num / gcd;
    den = den / gcd;
    return;
}

int main() {
    int a = 0, b = 0;
    read_rational(a,b);
    cout << a << " " << b << endl;
}
