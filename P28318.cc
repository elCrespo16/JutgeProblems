#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    int row, col, r1,c1;
    string a;
    cin >> row >> col;
    vector < vector<int> > v (row, vector <int> (col));
    for(int i = 0;i < row;++i){
        for(int j = 0;j < col;++j) {
            cin >> v[i][j];
        }
    }
    while(cin >> a) {
        if (a == "row") {
            cin >> r1;
            cout << "row " << r1 << ":";
            for(int j = 0;j < col;++j) {
                cout <<" " <<  v[r1 - 1][j];
            }
            cout << endl;
        }
        else if(a == "column") {
            cin >> c1;
            cout << "column " << c1 << ":";
            for(int j = 0;j < row;++j) {
                cout << " " << v[j][c1 - 1];
            }
            cout << endl;
        }
        else {
            cin >> r1 >> c1;
            cout << "element " << r1 << " " << c1 << ": " << v[r1 - 1][c1 - 1] << endl;
        }
    }
}
