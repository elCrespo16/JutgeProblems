#include <iostream>

using namespace std;
int pareja (int& b,int& marcador){
    int a;
    if (b == 0) return 0;
    a = b;
    cin >> b;
    if (a < b)++marcador;
    pareja (b,marcador);
    return marcador;
}

int main () {
    int a, b;
    cin >> a;
    for(int i = 0;i < a;++i) {
	cin >> b;
	int marcador = 0;
	cout << pareja (b, marcador) << endl;
    }
}