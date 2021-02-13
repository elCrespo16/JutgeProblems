#include <iostream>
#include <vector>


using namespace std;

typedef vector< vector<int> > Matrix;

void suelta (const Matrix& m,int a , int b) {
     for(int i = 0;i < a; ++i) {
         for(int j = 0;j < b; ++j) {
             cout << m[i][j];
         }
        cout << endl;
     }
}
void fill (Matrix& m,int a,int b) {
    for(int i = 0;i < a; ++i) {
         for(int j = 0;j < b; ++j) {
             cin >> m[i][j];
         }
     }
}

Matrix product(const Matrix& a, const Matrix& b){
    int m1 = a.size();
    int m1col = a[0].size();
    int m2 = b[0].size();
    Matrix res (m1,vector <int> (m2) );
    for(int i = 0;i < m1;++i) {
        for(int j = 0;j < m2;++j) {
            int sum = 0;
            for(int lel = 0;lel < m1col;++lel) {
                sum = sum + a[i][lel]* b[lel][j];
            }
            res[i][j] = sum;
        }
    }
    return res;
}

int main () {
    int a,b,c;
    while (cin >> a >> b >> c) {
        Matrix m1 (a,vector <int> (b));
        Matrix m2 (b,vector <int> (c));
        fill(m1,a,b);
	suelta(m1,a,b);
        fill(m2,b,c);
	suelta(m2,b,c);
	cout << endl;
        suelta(product(m1,m2),a,c);
    }
}