#include <iostream>
#include <vector>

using namespace std;

vector<int> concatenacio(const vector<int>& v1, const vector<int>& v2){
    int k = v1.size();
    int j = v2.size();
    vector<int> v = vector<int>(k+j);
    for (int i = 0;i < k;++i) {
	v[i] = v1[i];
    }
    for (int i = 0;i < j;++i) {
	v[i+k] = v2[i];
    }
    return v;
}

int main () {
    int a , b;
    cin >> a >> b;
    
}