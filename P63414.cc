#include <iostream>
#include <vector>

using namespace std;

int main () {
    int a, c;
    cin >> a;
    vector<int> v = vector<int>(1001,0);
    vector<int> s = vector<int>(1001);
    for (int i = 0;i < a;++i) {
	cin >> c;
	int aux =  c % 10000;
	v[aux] += 1;
	s[aux] = c;
    }
    for (int i = 0;i < 1001;++i) {
	if(v[i] > 0) cout << s[i] << " : " << v[i] << endl;
    }
}