#include <iostream>
#include <vector>

using namespace std;

void suelta (const vector<double>& v,const int& a) {
    for(int i = 0;i < a; ++i){
        cout << v[i];
    }
    cout << endl;
}

int max_pos (const vector<double>& v,const int& a) {
    double maximum = v[0]; 
    int last = 0;
    for(int i = 0;i <= a;++i) {
	if(v[i] > maximum){
	    maximum = v[i];
	    last = i;
	}
    }
    return last;
}
void swap (double& a, double& b) {
    double c = a;
    a = b;
    b = c;
}

void selection_sort(vector<double>& v, int m){
    if(m == 0 or m == -1)return;
    swap(v[m],v[max_pos(v,m)]);
    selection_sort(v,m - 1);
}
void read (vector<double>& v,const int& a) {
    for(int i = 0;i < a; ++i){
        cin >> v[i];
    }
}


int main () {
    int a;
    cin >> a;
    vector<double> v (a);
    read (v,a);
    selection_sort(v,a - 1);
    suelta(v,a);
}