#include <iostream>
using namespace std;

void morse(char c, int& n){
    if(c == 'a'){
	cout << ".-";
	 n += 2;
    }
    else if (c == 'e'){
	++n;
	cout << ".";
    }
    else if (c == 'i'){
	n += 2;
	cout << "..";
    }
    else if (c == 'o'){
	n += 3;
	cout << "---";
    }
    else {
	n += 3;
	cout << "..-";
    }
}

int main () {
    int ll, n = 0;
    char a;
    cin >> ll;
    while (cin >> a){
	morse(a,n);
	if(n >= ll){
	    n = 0;
	    cout << endl;
	}
    }
    if(n > 0 and n < ll)cout << endl;
    cout << "STOP" << endl;
}

