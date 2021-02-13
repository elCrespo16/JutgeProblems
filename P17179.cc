#include <iostream>

using namespace std;

void max_min(int b) {
    cout.setf(ios::fixed);
    cout.precision(4);
    double max, min, n, med;
    cin >> n;
    max = n;
    min = n;
    med = n;
    for(int i = 1;i < b;++i) {
	cin >> n;
	if (n > max) max = n;
	if (n < min) min = n;
	med = med + n;
    }
    cout << min << " " << max << " " << med/b << endl;
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);
    int a, b;
    cin >> a;
    for(int i = 0;i < a;++i) {
	cin >> b;
	max_min(b);
    }

}