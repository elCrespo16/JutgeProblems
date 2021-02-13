#include <iostream>
#include <vector>

using namespace std;

int posicio_maxim(const vector<double>& v, int m) {
    double max = v[0];
    int pos = 0;
    for(int i = 0;i <= m;++i){
	if(v[i] > max) {
	    max = v[i];
	    pos = i;
	}
    }
    return pos;
}

// int main () {
//     int a;
//     cin >> a;
//     vector<double> v = vector<double>(a);
//     for(
// }