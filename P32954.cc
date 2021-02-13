#include <iostream>
using namespace std;

void sort3(int& a, int& b, int& c){
    int max, min, med;
    if (a >= b and a >= c) {
	max = a;
	if (b >= c) {
	    med = b;
	    min = c;
	}
	else {
	    med = c;
	    min = b;
	}
    }
     else if (b >= a and b >= c) {
	max = b;
	if (a >= c) {
	    med = a;
	    min = c;
	}
	else {
	    med = c;
	    min = a;
	}
    }
    else if (c >= a and c >= b) {
	max = c;
	if (a >= b) {
	    med = a;
	    min = b;
	}
	else {
	    med = b;
	    min = a;
	}
    }
    c = max;
    b = med;
    a = min;
}

int main () {
    int a, b, c;
    while (cin >> a >> b >> c) {
	sort3(a, b, c);
	cout << a << " " << b << " " << c << endl;
    }
}