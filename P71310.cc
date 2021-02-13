#include <iostream>
#include <vector>
#include <string>

using namespace std;

double producte_escalar(const vector<double>& u, const vector<double>& v){
    int a = u.size();
    double total = 0;
    for (int i = 0;i < a;++i) {
	total = (u[i] * v[i]) + total;
    }
    return total;
}
int main () {
}