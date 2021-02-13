#include <iostream>
#include <vector>


using namespace std;

typedef vector< vector<int> > Matrix;


void suelta (const Matrix& m,const int row,const int col) {
     for(int i = 0;i < row; ++i) {
         for(int j = 0;j < col; ++j) {
             cout << m[i][j];
         }
        cout << endl;
     }
}
void fill (Matrix& m,const int row,const int col) {
    for(int i = 0;i < row; ++i) {
         for(int j = 0;j < col; ++j) {
             cin >> m[i][j];
         }
     }
}
void destroy(Matrix& m,const int starti,const int startj,const int fini, const int finj) {
    for(int i = starti;i <= fini;++i) {
        for(int j = startj;j <= finj;++j) {
            m[i][j] = 0;
        }
    }
}
int campos(Matrix& m,int row, int col) {
    int sum = 0,type = 0;
    int starti = 0,fini = 0,startj = 0,finj = 0; 
    for(int i = 0;i < row; ++i) {
         for(int j = 0;j < col; ++j) {
            // cultivo nuevo y destruir
            if(m[i][j] > 0){
                ++sum;
                type = m[i][j];
                starti = i;
                startj = j;
                for(int fila = i; fila < row;++fila) {
                    if(m[fila][j] == type) fini = fila;
                    else if(m[fila][j] == 0) fila = row;
                }
                for(int columna = j; columna < col;++columna) {
                    if(m[i][columna] == type)finj = columna;
                    else if(m[i][columna] == 0)columna = col;
                }
                destroy(m,starti,startj,fini,finj);
            }
         }
     }
    return sum;
}

int main () {
    int row, col;
    while (cin >> row >> col) {
        Matrix m (row, vector <int> (col));
        fill(m,row,col);
        cout << campos(m,row,col) << endl;
    }
}
