# include <iostream>
using namespace std;
//print int n in base b
void n_b(int n,int b){
	if(n < b){ 
		cout << n;		
		return;
	}
	n_b(n / b,b);
	cout << n % b;
	return;
	  
}
// print a char c ,n times
void print_ntimes (int n, char c){
	if(n == 0)return;
	cout << c;
	print_ntimes(n-1,c);
}
//return the number of digits of n in base b
int num_dig(int n,int b){	
	if (n < b) return 1;
	return 1 + num_dig(n/b,b);
}

void format(int n, int b,int c){
	int num = num_dig(n,b);
	if(num > c){
		print_ntimes(c,'*');
	}
	else if(num == c){
		n_b(n,b);
	}
	else {
		print_ntimes(c-num,'#');
		n_b(n,b);
	}
}

int main() {
	int n, b, c;
	while (cin >> n >> b >> c) {
		format(n,b,c);
		cout << endl;
	}
	
}
