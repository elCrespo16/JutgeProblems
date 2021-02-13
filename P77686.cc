#include <iostream>
using namespace std;

bool es_capicua(int n) {
    int i;
    int r;
    int num = 0;
    i = n;
    while (i != 0) {
	r = i % 10;
	i = i / 10;
	num = num * 10 + r;  
    }
    if (n == num) return true;
    else return false;
}

int main () {
    int n;
    while(cin >> n) {
	if (es_capicua(n) == 0) cout << "false" << endl;
	else cout << "true" << endl;
    }
}