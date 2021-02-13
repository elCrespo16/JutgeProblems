#include <iostream>
#include <iostream>
using namespace std;
 int main() {
     cout.setf(ios::fixed);
     cout.precision(4);
    int n;
    int m;
    double c = 0;
    cin >> n;
    m = 1;
    while (m <= n) {
	c = c + 1.0 / m;
	++m;
    }
    cout << c << endl; 
}