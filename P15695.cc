#include <iostream>
using namespace std;

 bool isPrime(long num, int& z) {
    if (num == 2) return true;
     if (num % 2 == 0){
        z = 2;
        return false;
    }
    for(int i = 3;i*i <= num;i += 2) {
		if ((num % i) == 0){
            z = i;
            return false;
        }
    }
    return true; 
}
 
 
int largest_prime_factor(int n){
    int z = 0;
    if(isPrime(n,z))return n;
    while(not isPrime(n,z)){
        n = n / z;
    }
    return n;
}

int main () {
    int n;
    cin >> n;
    cout << largest_prime_factor(n) << endl;
}
