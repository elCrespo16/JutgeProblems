#include <iostream>
#include <vector>

using namespace std;

typedef vector < vector <char> > Matrix;

bool busca(Matrix& map, int x, int y){
	if(map[x][y] == 't') return true;
	if(map[x][y] == '.'){
		map[x][y] = 'X';
		return busca(map,x+1,y) or busca(map,x-1,y) or busca(map,x,y+1) or busca(map,x,y-1);
	}
	return false;
}

int main () {
	int n, m, x, y;
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
	if(busca(map,x,y))cout << "yes" << endl;
	else cout << "no" << endl;
}
