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
void fill (Matrix& m,const int a,const int b) {
   for(int i = 0;i < a; ++i) {
         for(int j = 0;j < b; ++j) {
             cin >> m[i][j];
         }
     }
}

void min_max(const Matrix& mat, int& minimum, int& maximum) {
    bool fi = true;
    int x;
    int a = mat.size();
    int b = mat[0].size();
    for(int i = 0;i < a; ++i) {
         for(int j = 0;j < b; ++j) {
	    x = mat[i][j];
	    if(fi){
		fi = false;
		minimum = x;
		maximum = x;
	    }
	    else if (x < minimum) minimum = x;
	    else if (x > maximum) maximum = x;
         }
     }
}

int main () {
    int a,b, minimum ,maximum ,count = 1,nmat = 0,dif = 0;
    bool fi = true;
    while(cin >> a >> b) {
	Matrix m1 (a,vector <int> (b));
	fill(m1,a,b);
	min_max(m1,minimum,maximum);
	if(fi) {
	    fi = false;
	    dif = maximum - minimum;
	    nmat = 1;
	}
	else if(maximum - minimum > dif){
	    dif = maximum - minimum;
	    nmat = count;
	}
	++count;
    }
    cout << "la diferencia maxima es " << dif << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << nmat << endl;
}
