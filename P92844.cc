#include <iostream>
#include <vector>


using namespace std;

typedef vector<char> Fila; 
typedef vector<Fila> Rectangle;

int arriba (char c, const Rectangle& r,int row, int col) {
    for(int i = 0;i < row; ++i) {
         for(int j = 0;j < col; ++j) {
            if(r[i][j] == c)return i;
         }
     }
     return 0;
}
int izq (char c, const Rectangle& r,int row, int col) {
    for(int i = 0;i < col; ++i) {
         for(int j = 0;j < row; ++j) {
            if(r[j][i] == c)return i;
         }
     }
     return 0;
}
int der (char c, const Rectangle& r,int row, int col) {
    for(int i = col - 1;i >= 0; --i) {
         for(int j = row - 1;j >= 0; --j) {
            if(r[j][i] == c)return i;
         }
     }
    return 0;
}
int abajo (char c, const Rectangle& r,int row, int col) {
     for(int i = row - 1;i >= 0; --i) {
         for(int j = col - 1;j >= 0; --j) {
            if(r[i][j] == c)return i;
         }
     }
     return 0;
}

void dimensions_minimes(char c, const Rectangle& r, int& fils, int& cols){
    int row = r.size(), col = r[0].size();
    fils = abajo(c,r,row,col) - arriba(c,r,row,col) + 1; 
    cols = der(c,r,row,col) - izq(c,r,row,col) + 1;
}

int main () {
}
