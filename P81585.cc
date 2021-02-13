#include <iostream>
#include <vector>

using namespace std;

bool sumrest(int total,const vector<int>& v) {
    int a = v.size();
    for(int i = 0;i < a;++i) {
	if(v[i] == (total - v[i])) return true;
    }
    return false;
}

int main () {
    int a, b;
    bool gra;
    while (cin >> a) {
	int total = 0;
	vector<int> v = vector<int>(a);
	for(int i = 0;i < a;++i) {
	    cin >> b;
	    v[i] = b;
	    total = total + b;
	}
	gra = sumrest(total,v);
	if(gra)cout << "YES";
	else cout << "NO";
	cout << endl;
    }
}