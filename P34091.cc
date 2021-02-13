#include <iostream>
#include <string>
using namespace std;
bool es_perfecte(int n) {
 if (n == 6 or n == 28 or  n == 496 or n == 8128 or n == 33550336) return true;
 else return false;
}
int main () {
    int n;
    while (cin >> n) {
	if (es_perfecte(n) == 1) cout << "true" << endl;
	else cout << "false" << endl;
    }
}