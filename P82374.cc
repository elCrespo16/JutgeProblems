#include <iostream>
using namespace std;

//dice si un int esta dentro de unos intervalos
int main () {
    int x, a, b, c, d, ex;
    cin >> x >> a >> b >> c >> d;
    if (x >= a and x <= b) cout << "yes" << endl;
    else if (x >= c and x <= d) cout << "yes" << endl;
    else cout << "no" << endl;
}