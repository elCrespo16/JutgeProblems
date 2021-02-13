#include <iostream>
#include <vector>

using namespace std;

int main () {
    int a, b, c = 0;
    cin >> a;
    vector<int> v = vector<int>(a);
    for (int i = 0;i < a;++i) {
	cin >> b;
	v[i] = b;
    }
    for(int j = 0;j < a-1;++j) {
	if(v[j] == v[a-1]) ++c;
    }
    cout << c << endl;
}