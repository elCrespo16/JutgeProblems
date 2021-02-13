#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> fila;
typedef vector<fila> matrix;

bool esquinas(int x, int y, int lineas, int columnas) {
    return (y == lineas - 1 and x == columnas - 1)/*derecha abajo*/
    or (y == 0 and x == lineas - 1)/*derecha arriba*/ 
    or (y == columnas - 1 and x == 0)/*izquierda abajo*/
    or (y == 0 and x == 0); /*izquierda arriba*/
}

void bola_posicion(matrix& m,int a, int b) {
    bool firts = 1;
    int x = 0, y = 0,cx = 1,cy = 1;
    m[0][0] = '0';
    while(not esquinas(x,y,a,b) or firts) {
	firts = 0;
	x = x + cx;
	y = y + cy;
	m[x][y] = '0';
	if (x == a-1) cx = -1;
	else if (y == 0) cy = 1;
	if (y == b - 1) cy = -1;
	else if (x == 0) cx = 1;
    }
}

int main () {
    int a,b;
    while(cin >> a >> b) {
	for(int prl = -2;prl < b;++prl) cout << "#";
	cout << endl;
	matrix m = vector<fila>(a,fila(b,' '));
	bola_posicion(m,a,b);
	for(int i = 0;i < a;++i) {
	    cout << "#";
	    for(int o = 0;o < b;++o) {
		cout << m[i][o];
	    }
	    cout << "#" << endl;
	}
	for(int prl = -2;prl < b;++prl) cout << "#";
	cout << endl << endl;
    }
}