#include <iostream>
using namespace std;

//saca la tabla del numero
int main () {
    int num;
    cin >> num;
    for(int i = 1;i <= num;++i) cout << num <<" x " << i << " = " << num*i << endl;
}