#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> fila;
typedef vector<fila> matrix;

bool todos(const vector<bool>& numero,int a) {
    for(int i = 1;i < a*a;++i) {
	if(not numero[i]) return false;
    }
    return true;
}

/*bool filas_columnas_diagonales (const matrix& m,int a) {
    int suma1 = 0, sumrest;
//     la suma principal
    for(int i = 0;i < a;++i) suma1 = suma1 + m[0][i];
//     filas
    for(int i = 1;i < a;++i) {
	sumrest = 0;
	for(int o = 0;o < a;++o) {
	    sumrest = sumrest + m[i][o];
	}
	if(sumrest != suma1) return false;
    }
//     columnas
    for(int i = 0;i < a;++i){
	sumrest = 0;
	for(int o = 0;o < a;++o) {
	sumrest = sumrest + m[o][i];   
	}
	if (sumrest != suma1)return false;
    }
//     diagonal 1
    sumrest = 0;
    for(int i = 0;i < a;++i) {
	sumrest = sumrest + m[i][i];
    }
    if(sumrest != suma1)return false;
//     diagonal 2
    sumrest = 0;
    for(int i = a-1;i >= 0;--i){
	sumrest = sumrest + m[i][i];
    }
    if(sumrest != suma1)return false;
    return true;
}*/

void entrada (matrix& m,vector<bool>& numero,const int a) {
    for (int i = 0;i < a;++i) {
	for(int o = 0;o < a;++o) {
	    cin >> m[i][o];
	    numero[m[i][o] - 1] = true;
	}
    }
}

bool todoIgual(const vector<int>& sumas, int sumadia1, int sumadia2) {
    int comp = 0;
    if (sumas.size() > 0) comp = sumas[0];
    if (comp != sumadia1 or comp != sumadia2) return false;
    for (int i = 1; i < sumas.size(); ++i) {
	if (sumas[i] != comp or comp != sumadia1 or comp != sumadia2) return false;
    }
    return true;
}

bool comprobar(const matrix& m, int a) {
    int sumadia1 = 0,sumadia2 = 0;
    vector<int> sumas = vector<int>(a*2,0);
    for (int i = 0; i < a; ++i) {
	for (int j = 0; j < a; ++j) {
	    sumas[i] += m[i][j];
	    sumas[i+a] += m[j][i];
	}
	sumadia1 += m[i][i];
	sumadia2 += m[i][a - i - 1];
    }
    if (not todoIgual(sumas,sumadia1, sumadia2)) return false;
    return true;
}

int main () {
    int a;
    while(cin >> a) {
	matrix m = vector<fila>(a,fila(a));
	vector<bool> numero = vector<bool>(a*a,false);
	entrada(m,numero,a);
	if(not todos(numero,a)) cout << "no" << endl;
	else if(not comprobar(m,a))cout << "no" << endl;
	else cout << "si" << endl;
    }
}