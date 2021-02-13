#include <iostream>
#include <vector>

using namespace std;

bool hi_es(int x, const vector<int>& v){
    int n = v.size();
    for (int i = 0; i < n; ++i)  {
	if (x == v[i]) return true;
    }
    return false;
}

int main () {
    vector<int> v = vector<int>(1,0);
    v[0] = 1;
    cout << v[0] << endl;
}