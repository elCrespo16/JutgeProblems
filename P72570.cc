#include <iostream>
using namespace std;

void llegeix_hora(int& h, int& m, int& s){
    char c;
    cin >> c;
    while(cin >> c and c != '|') {
	if(c == '*')h = h * 2 + 1;
	else h = h * 2;
    }
    while(cin >> c and c != '|') {
	if(c == '*')m = m * 2 + 1;
	else m = m * 2;
    }
    while(cin >> c and c != '|') {
	if(c == '*')s = s * 2 + 1;
	else s = s * 2;
    }
    
}

void escriu_hora(int h, int m, int s){
    llegeix_hora(h,m,s);
    cout << h << ":" << m << ":" << s << endl;
}

int main () {
    int a;
    cin >> a;
    for(int i = 0;i < a;++i) { 
	escriu_hora(0,0,0);
    }
}