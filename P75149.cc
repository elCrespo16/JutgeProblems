#include <iostream>
#include <string>

using namespace std;

int main() {
    char letra;
    bool a = 0;
    while (cin >> letra and a != '.'){
	if (letra == 'a')a = 1;
    }
    if (a == 0) cout << "no" << endl;
    else cout << "si" << endl;
}