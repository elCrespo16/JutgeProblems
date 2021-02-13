#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fill(vector <int>& v,const int& v_size) {
    for(int i = 0;i < v_size;++i){
	cin >> v[i];
    }
}

void suelta(const vector <int>& v,const int& v_size) {
    if(v_size > 0)cout << v[0]; 
    for(int i = 1;i < v_size;++i){
	cout << " " << v[i];
    }
}

bool increasing (int a,int b) {
    return a > b;
}
int main () {
    int k;
    while (cin >> k) {
	vector <int> v (k);
	fill(v,k);
	sort (v.begin(),v.end(),increasing);
	suelta (v,k);
	cout << endl;
    }
}
