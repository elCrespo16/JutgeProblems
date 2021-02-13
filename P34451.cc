#include <iostream>
using namespace std;

//saca el numero de multiplos
int main () {
    int num, x, sum = 0;
    cin >> num;
    while (cin >> x) if((x % num) == 0)++sum;
    cout << sum << endl;
}