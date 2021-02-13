#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    int a;
    string pal;
    cin >> a;
    vector<string> v = vector<string>(a);
    for (int i = 0;i < a;++i) {
	cin >> pal;
	v[i] = pal;
    }
    for (int i = a-1;i >= 0;--i){
	int legh = v[i].size();
	for(int h = legh-1;h >= 0;--h) {
	    cout << v[i][h];
	}
	cout << endl;
    }
}