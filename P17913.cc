#include <iostream>

using namespace std;
int double_factorial(int x) {
    int k = 1;
    for (int a = x;a > 0;a = a - 2) {
    k = k * a;
    }
    return k;
}

int main () {
    int x;
    cin >> x;
    cout << double_factorial(x) << endl;
}