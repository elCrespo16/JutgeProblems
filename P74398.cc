#include <iostream>
using namespace std;


int main () {
    int a;
    cin >> a;
    for(int i = 2;i < 17;++i) {
        int xi = 1, b = i;
        while (b <=  a) {
            b = b * i;
            ++xi;
        }
    cout << "Base " << i << ": " << xi << " cifras." << endl;
    }
}
        
        
