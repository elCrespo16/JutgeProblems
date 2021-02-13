#include <iostream>
using namespace std;

int main(){
	int a, b, cont = 1;
	while(cin >> a >> b){
		cout << "#" << cont << " : ";
		if(a % b == 0) cout << a << endl;
		else {
			int c = a / b;
			++c;
			cout << c * b << endl;
		}
		++cont;
	}
}