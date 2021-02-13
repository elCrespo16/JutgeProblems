#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool es_palindrom(const string& s){
    int n = s.length();
    int a = 0, b;
    b = n - 1;
    n = n / 2;
    for (int i = 0;i <= n;++i) {
	if(s[a] != s[b])return false;
	++a;
	--b;
    }
    return true;
}
int main () {
}