#include <iostream>
#include <vector>


using namespace std;

typedef vector< vector<int> > Matriu;

void transposa(Matriu& m){
    int msize = m.size(), copy = 0;
     for(int i = 0;i < msize; ++i) {
         for(int j = 0;j < msize; ++j) {
             if(j > i) {
                 copy = m[i][j];
                 m[i][j] = m[j][i];
                 m[j][i] = copy;
             }
         }
     }
}
