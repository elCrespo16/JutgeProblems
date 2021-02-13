#include <iostream>
#include <vector>

using namespace std;

typedef vector < vector <char> > Matrix;

void busca(Matrix& map, int x, int y, int &z){
	if(map[x][y] == '.' or map[x][y] == 't'){
		if(map[x][y] == 't') ++z;
		map[x][y] = 'X';
		busca(map,x+1,y,z);
		busca(map,x-1,y,z);
		busca(map,x,y+1,z);
		busca(map,x,y-1,z);
	}
}

int main () {
	int n, m, x, y, z = 0;
	cin >> n >> m;
	n = n + 2;
	m = m + 2;
	Matrix map(n,vector<char>(m));
	for (int i = 0;i < n;++i){
		for(int j= 0;j < m;++j){
			if(i==0 or j== 0 or i == n-1 or j == m-1)map[i][j] == 'X';
			else cin >> map[i][j];
		}
	}
	cin >> x >> y;
	busca(map,x,y,z);
	cout << z << endl;
}
