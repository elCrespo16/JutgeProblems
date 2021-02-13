#include <iostream>

using namespace std;

void count_and_add(int& num, int& sum){
    int i;
    sum = 0;
    num = 0;
    while (cin >> i) {
	++num;
	sum = sum + i;
    }
}

int main() {
    int num = 0, sum = 0;
    count_and_add(num, sum);
}