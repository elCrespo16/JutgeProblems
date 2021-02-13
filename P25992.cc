#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
const int N_MAX = 1000;
 
typedef vector<int> Fila;
 
int main() {
        Fila p(N_MAX);
        Fila s(N_MAX);
        int i = 0;
        int j = 0;
        int n;
        while (cin >> n) {
                if (n != 0) {
                        if (n%2 == 0) {
                                p[i] = n;
                                ++i;
                        }
                        else {
                                s[j] = n;
                                ++j;
                        }
                }
                else {
                        sort (p.begin(), p.begin() + i);
                        sort (s.begin(), s.begin() + j);
                        if (i > 0) cout << p[0];
                        for (int k = 1; k < i; ++k) cout << ' ' << p[k];
                        cout << endl;
                        if (j > 0) cout << s[j - 1];
                        for (int k = j - 2; k >= 0; --k) cout << ' ' << s[k];
                        cout << endl;
                        i = j = 0;    
                }
        }
}