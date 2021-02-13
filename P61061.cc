#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int m = 1;
			if(n / 10 == 0) cout << "The product of the digits of " << n << " is " << n << "." << endl;
			else {
				while(n / 10  != 0){
					cout << "The product of the digits of " << n << " is " ;
					while(n != 0){
						m = m * (n%10);
						n = n / 10;
					}
					cout << m << "." << endl;
					n = m;
					m = 1;
				}
			}
			cout << "----------" << endl;	
		}
		
}