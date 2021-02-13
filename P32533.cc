#include <iostream>
using namespace std;


void pl (int n) {
    for(int i = 0;i < n;++i) {
        cout << "+" ;
    }
    cout << "/";
}

void ast (int n) {
    for(int i = 0;i < n;++i) {
        cout << "*";
    }
    cout << endl;
}

int main () {
    int n;
    cin >> n;
    for (int sq = 0;sq < n;++sq) {
        pl (n - (sq + 1));
        ast(sq);
    }
}
