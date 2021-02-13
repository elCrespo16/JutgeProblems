#include <iostream>

using namespace std;

int max (int a) {
    int max1, max2;
    cin >> max1;
    max2 = max1;
    for (int i = 1;i < a;++i){
	cin >> max1;
	if (max1 >= max2)max2 = max1;
    }
    return max2;
}

int main () {
    int a;
    while (cin >> a){
	cout << max (a) << endl;
    }
}