#include <iostream>

using namespace std;

int sumatorio(int a) {
    int b = 0;
    for(int i = 1;i <= a;++i) {
	b = b + i;
    }
    return b;
}

int main () {
    int a, d;
    while(cin >> a) {
	int sum = sumatorio(a);
	int num = 0;
	for (int i = 1;i < a;++i){
	    cin >> d;
	    num = num + d;
	}
	cout << sum - num << endl;
    }
}