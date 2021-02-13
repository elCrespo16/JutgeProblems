#include <iostream>
#include <vector>


using namespace std;

typedef vector< vector<int> > Matrix;

void suelta (const Matrix& m) {
    int msize = m.size();
     for(int i = 0;i < msize; ++i) {
         for(int j = 0;j < msize; ++j) {
             cout << m[i][j];
         }
        cout << endl;
     }
}
void fill (Matrix& m) {
    int msize = m.size();
    for(int i = 0;i < msize; ++i) {
         for(int j = 0;j < msize; ++j) {
             cin >> m[i][j];
         }
     }
}

Matrix product(const Matrix& a, const Matrix& b){
    int m1 = a.size();
    Matrix res (m1,vector <int> (m1) );
    for(int i = 0;i < m1;++i) {
        for(int j = 0;j < m1;++j) {
            int sum = 0;
            for(int lel = 0;lel < m1;++lel) {
                sum = sum + a[i][lel]* b[lel][j];
            }
            res[i][j] = sum;
        }
    }
    return res;
}

int main () {
    int a;
    while (cin >> a) {
        Matrix m1 (a,vector <int> (a));
        Matrix m2 (a,vector <int> (a));
        fill(m1);
        fill(m2);
        suelta(product(m1,m2));
    }
}
