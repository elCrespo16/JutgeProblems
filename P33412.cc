#include <iostream>
#include <vector>

using namespace std;



    bool resistant_search(double x, const vector<double>& v) {
    
    if (v.size() == 0) return false; // Vector buit
    
    int esq = 0, dre = v.size()-1, mig;
    
    
    while (esq+1 < dre) {
        mig = (dre+esq)/2;
        
        if (v[mig] == x or v[mig+1] == x or v[mig-1] == x) return true; // Hem de comparar les posicions contigues
        else if (v[mig] > x) dre = mig;
        else esq = mig;
        
    }
    
    if (v[dre] == x) return true;
    else if (v[esq] == x) return true;
    else return false;
}

int main() {
    int n;
    double x;
    cin >> n >> x;
    vector<double> v(n);
    for(int i= 0;i <n;++i){
        cin >> v[i];
    }
    cout << resistant_search(x,v) << endl;
}
