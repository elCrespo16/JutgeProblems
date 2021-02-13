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

void bubble_sort(vector<double>& v){
    bool swaped = true;
    int n = v.size();
    while (swaped){
	swaped = false;
	for(int i = 0;i < n - 1;++i) {
	    if(v[i] > v[i + 1]){
		swap(v[i],v[i + 1]);
		swaped = true;
	    }
	}
    }
}


int main () {
    int a;
    cin >> a;
    vector<double> v (a);
    read (v,a);
    bubble_sort(v);
    suelta(v,a);
}