#include <iostream>
#include <vector>
using namespace std;


int main () {
	int n;
	while(cin >>n) {
		int suma1 = 0, suma2 =0, sm = 0, a ;
		vector<int> v (n);
		for(int i = 0;i < n;++i){
			cin >> a;
			v[i] = a;
			sm = sm + a;
			if(sm > suma1)suma1 = sm;
		}
		sm = 0;
		for(int i = n-1;i >= 0;--i) {
			sm = sm + v[i];
			if(sm > suma2)suma2 = sm;
		}
		cout << suma1 << " " << suma2 << endl;
	}
}