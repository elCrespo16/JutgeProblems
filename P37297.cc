#include <iostream>
using namespace std;

//saca la suma de los ultimos 3 numeros
int main () {
    int num, a = 0, b = 0, c = 0;
    cin >> num;
    num = num % 1000;
    a = num % 10;
    c = num / 100;
    num = num % 100;
    b = num / 10;
    cout << a + b + c << endl;
}