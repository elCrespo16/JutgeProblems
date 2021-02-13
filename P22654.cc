#include <iostream>

using namespace std;

void descompon(int n, int& h, int& m, int& s) {
    if (n >= 3600) {
	h = n / 3600;
	m = (n % 3600) / 60;
	s = (n % 3600) % 60;
    }
    else if (n < 3600 and n >= 60) {
	h = 0;
	m = n / 60;
	s = n % 60;
    }
    else {
	h = 0;
	m = 0;
	s = n;
    }
}

int main () {
    int n;
    while (cin >> n) {
	int h = 0,m = 0, s = 0;
	descompon(n, h, m, s);
	cout << h << " " << m << " " << s << endl;
    }
}