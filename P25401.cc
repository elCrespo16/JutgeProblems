#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fill (vector <int>& v,const int& a){
     for(int i = 0;i < a;++i) {
	cin >> v[i];
    }
}

int diferent(const vector <int>& v,const int& a) {
    int counter = 1, aux;
    aux = v[0];
    for (int i = 0;i < a;++i) {
	if(v[i] != aux){
	    ++counter;
	    aux = v[i];
	}
    }
    return counter;
}

int main() {
    int v_size;
    while (cin >> v_size) {
	vector <int> v (v_size);
	fill (v,v_size);
	sort(v.begin(),v.end());
	cout << diferent(v,v_size) << endl;
    }
}