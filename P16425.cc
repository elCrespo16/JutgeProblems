#include <iostream>
#include <vector>

using namespace std;

const int n = 7920;

int main () {
    vector <bool> num (n,true);
    vector <int> prime (1001);
    int in = 0;
    num[0] = num[1] = true;
    for(int i = 2;i < n;++i) {
	if(num[i] == true) {
	    prime[in] = i;
	    ++in;
	    for(int j = i + i;j < n;j = j + i)num[j] = false;
	}
    }
    int k;
    while (cin >> k) {
	bool fi = true;
	for(int i = 0;i < k;++i) {
	    if(fi){
		cout << prime[i];
		fi = false;
	    }
	    else cout << "," << prime[i];
	}
	cout << endl;
    }
}