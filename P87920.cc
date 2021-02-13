#include <iostream>
#include <vector>

using namespace std;

int leer_suma_vector(vector<int>& v, int v_size) {
	int sum =0, a ;
	for(int i = 0;i < v_size;++i) {
		cin >> a;
		v[i] = a;
		sum = sum + a;
	}
	return sum;
}
bool esta (const vector<int> v,const int sum, const int vsize) {
	for(int i = 0;i < vsize;++i) {
		if (v[i] == sum - v[i])return true;
	}
	return false;
}

int main () {
	int a;
	while(cin >> a) {
		vector<int> v (a);
		int  sum = leer_suma_vector(v,a);
		if (esta (v,sum,a))cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}