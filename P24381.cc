#include <iostream>
#include <string>
using namespace std;
void cross(int n, char c) {
    int d = n / 2;
//     columnas arriba
    for(int col = 0;col < d;++col){
// 	lado izquierdo X
	for (int li = 0;li < d;++li) {
	    cout << " ";
	}
// 	X
	cout << c << endl;
	}
	for(int car = 0;car < n;++car) cout << c;
	cout << endl;
// 	columna abajo
	for(int col = 0;col < d;++col){
// 	    lado izquierdo X
	    for (int li = 0;li < d;++li) {
		cout << " ";
	    }
// 	    X
	    cout << c << endl;
	}    
}

int main () {
    int n;
    char c;
    while (cin >> n >> c) {
	cross(n, c);
    }
}