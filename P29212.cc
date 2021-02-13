#include <iostream>

using namespace std;

int fast_exp(int n, int k, int m){
    if (k == 0)return 1;
    int res_ant = fast_exp(n, k / 2,m);
    res_ant = res_ant % m;
    int res_act = res_ant * res_ant;
    res_act = res_act % m;
    if(k % 2 == 0)return res_act;
    return (res_act * n) % m;
}

int main() {
    int n, m, k;
    while(cin >> n >> k >> m) cout << fast_exp(n % m, k, m) << endl;
}
