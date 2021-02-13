#include <iostream>
using namespace std;

 int absolute(int n) {
     if (n < 0) return n * -1;
     return n;
 }
 
 
int main () {
    int n;
    cin >> n;
    cout << absolute(n) << endl;
}