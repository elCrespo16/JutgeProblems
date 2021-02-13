#include <iostream>
#include <vector>

using namespace std;


int first_occurrence(double x, const vector<double>& v, int left, int right){
    if(left > right)return -1;
    int a = (left+right)/2;
    if(v[a] > x)return first_occurrence(x,v,left,a - 1);
    if(v[a] == x){
        if(a == 0) return 0;
        if(v[a - 1] == x)return first_occurrence(x,v,left,a - 1);
        return a;
    }
    if(v[a] < x)return first_occurrence(x,v,a + 1,right);
    return a;
}

int first_occurrence(double x, const vector<double>& v){
   return first_occurrence(x,v,0,v.size()-1);
}

void read (vector<double>& v,const int& a) {
    for(int i = 0;i < a; ++i){
        cin >> v[i];
    }
}
int main () {
    int a;
    double x;
    cin >> a;
    vector<double> v (a);
    cin >> x;
    read(v,a);
    int left, right;
    left = 0;
    right = a - 1;
    cout << first_occurrence(x,v,left,right) << endl;
}
