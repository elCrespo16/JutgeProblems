# include <iostream>
using namespace std;

int fatten(int x){	
	if(x < 10)return x;
	int a = fatten (x/10);
	if(x % 10 > a % 10)a = a * 10 + x % 10;
	else a = a * 10 + a % 10;
	return a;
}

int main () {
	int x;
	cin >> x;
	cout << fatten(x) << endl;	
}
