#include <iostream>
#include <vector>

using namespace std;

int main () {
    int a, b;
    while (cin >> a) {
	vector<int> v = vector<int>(a);
	int n = v.size();
	for (int i = 0;i < a;++i) {
	    cin >> b;
	    v[i] = b;
	}
	for(int j = a-1;j != -1;--j) {
	    cout << v[j];
	    if(j != 0)cout << " ";
	}
	cout << endl;
    }
}