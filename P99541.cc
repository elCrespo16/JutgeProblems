#include <iostream>
#include <string>
using namespace std;

void print(int s, char c, int n){
    for (int i = 0;s > i;++i) {
	cout << " ";
    }
    for (int i = 0;n > i;++i) {
	cout << c;
    }
    cout << endl;
}

int main () {
    int s, n;
    char c;
    while (cin >> s >> c >> n) {
	print(s, c , n);
    }
    
}