#include <iostream>

using namespace std;

bool parentesis (char c) {
    bool a;
    char d;
    if (cin >> d){
	if (c == '(' and d == ')')return true;
	if (d == '(' and c == '(')a = parentesis(d);
	else return false;
    }
    else return false;
    return a * parentesis(c);
}

int main () {
    bool si = 1;
    char c;
    while (cin >> c and si) {
	if(not parentesis (c))si = 0;    
    }
    if(si == 1)cout << "si" << endl;
    else cout << "no" << endl;
}