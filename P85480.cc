#include <iostream>
#include <vector>
using namespace std;

bool isPrime(const long num) {
    if (num < 2) return false;
    if (num == 2)return true;
    if (num % 2 == 0) return false;
    for(int i = 3;i*i <= num;i += 2) {
		if ((num % i) == 0) return 0;
    }
    return true; 
}

bool sumprim (const vector<int> v ,const int vsize ){
	for (int i = 0;i < vsize;++i){
		for (int j = i + 1;j < vsize;++j){
			if(isPrime(v[i] + v[j]))return true;
		}
	}
	return false;
}
void leer_vector ( vector<int>& v, const  int v_size) {
	for(int i = 0;i < v_size;++i) {
		cin >> v[i];
	}
}

int main (){
	int a;
	while (cin >> a){
		vector<int> v (a);
		leer_vector(v,a);
		if (sumprim(v,a))cout << "yes";
		else cout << "no" ;
		cout << endl;
	}
}