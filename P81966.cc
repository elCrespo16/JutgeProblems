#include <iostream>
#include <vector>

using namespace std;


int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (esq > dre) return -1;
    if (esq == dre) {
	if (v[esq] == x) return esq;
	else return -1;
    }
    int p = (esq + dre)/2;
    if(v[p] > x) return posicio(x,v,esq,p);
    if(v[p] < x) return posicio(x,v,p+1,dre);
    return p;
}





int main () {}
