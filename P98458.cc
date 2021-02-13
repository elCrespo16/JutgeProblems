#include <iostream>

using namespace std;

void min_max(int a, int b, int& mn, int& mx){
    if (a > b) {
	mx = a;
	mn = b;
    }
    else {
	mn = a;
	mx = b;
    }
}
int main () {
    int a , b, mn = 0, mx = 0;
    while(cin >> a >> b) {
	min_max(a, b, mn, mx);
	cout << mn << " " << mx << endl;
    }
}