#include <iostream>

using namespace std;
int factorial(int n) {
    int k = 1;
    for (int a = 1;a <= n;++a) {
    k = k * a;
    }
    return k;
}

int main () {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
}