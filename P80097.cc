#include <iostream>

using namespace std;

void pinta_rusc(int f, int c){
    bool pri = true;
    for(int fi = 0;fi < f*2+1;++fi) {
	for (int col = 0;col < c;++col) {
	    if(pri){
		cout << " _";
		if (col < c - 1) cout << "  ";
	    }
	    else if(fi%2 != 0){ cout << "/ \\";
		if (col < c - 1) cout << "_";
	    }
	    else if (fi%2 == 0){
		cout << "\\_/";
		if (col < c - 1) cout << " ";
	    }
	}
	cout << endl;
	pri = false;
    }
}

int main () {
    int a, b, c = 0;
    while(cin >> a >> b) {
	if(c != 0) cout << endl;
	pinta_rusc(a,b);
	++c;
    }
}