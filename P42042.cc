#include <iostream>
#include <string>
using namespace std;

int main () {
    char le;
    int c ;
    cin >> le;
    if (le >= 'a' and le <= 'z'){
	cout << "minuscula" << endl ;
	c='Z'-'z';
	le=le+c;
    }
    else {
	cout << "majuscula" << endl ;
    }
    if (le=='A' or le=='E' or le=='U' or le=='I' or le=='O'){
	cout << "vocal" << endl;
    }
    else {
	cout << "consonant" << endl;
    }
}
    