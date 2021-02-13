#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    string a;
    while(cin >> a) {
	int n = a.length();
	for(int i = n-1;i >= 0;--i) {
	    cout << a[i];
	}
	cout << endl;
    }
}