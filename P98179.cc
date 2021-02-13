#include <iostream>
#include <vector>

using namespace std;

void suelta (const vector<double>& v,const int& a) {
    for(int i = 0;i < a; ++i){
        cout << v[i];
    }
    cout << endl;
}
void swap (double& a, double& b) {
    double c = a;
    a = b;
    b = c;
}
void read (vector<double>& v,const int& a) {
    for(int i = 0;i < a; ++i){
        cin >> v[i];
    }
}
void shift(vector<double>& v, int i){
    int n = v.size();
    double c = v[i];
    v[i] = v[n - 1];
    for(int j = i + 1;j < n;++j) {
	double a = v[j];
	v[j] = c;
	c = a;
    }
}

void insert(vector<double>& v){
    int n = v.size();
    double last = v[n - 1];
    bool found = false;
    for(int i = 0;i < n and not found;++i) {
	if(v[i] > last){
	    found = true;
	    shift(v,i);
	}
    }
}

int main () {
    int a;
    cin >> a;
    vector<double> v (a);
    read (v,a);
    insert(v);
    suelta(v,a);
}