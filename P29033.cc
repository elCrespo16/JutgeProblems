#include <iostream>
#include <vector>
#include <list>

using namespace std;



struct lst{
	list <int> adj;
	char pint;
	bool visited;
};

typedef vector < lst > matrix; 
bool DFS(matrix& m,int i, int ant, char pintant){
	if(m[i].pint == pintant)return false;
	if(m[i].visited)return true;
	m[i].visited = true;
	char pintu;
	if(m[i].pint == 'N'){
		if(pintant == 'r'){
			pintu = 'n';
		}
		else pintu = 'r';
		m[i].pint = pintu;
	}
	list<int>:: iterator it = m[i].adj.begin();
	while(it !=  m[i].adj.end()){
		if((*it) != ant){
			if(not DFS(m,(*it),i,pintu))return false;
		}
		++it;
	}
	return true;
}

int main () {
	int v;
	while(cin >> v){
		int e, v1, v2;
		cin >> e;
		lst a;
		a.pint = 'N';
		a.visited = false;
		matrix m (v,a);
		for(int i = 0;i < e;++i){
			cin >> v1 >> v2;
			m[v1].adj.push_back(v2);
			m[v2].adj.push_back(v1);
		}
		bool bien = true;
		for(int i=0;i < v and bien;++i){
			if(not m[i].visited){
				bien = DFS(m,i,-1,'r');
			}
		}
		if(not bien)cout << "no" << endl;
		else cout << "yes" << endl;	
	}
}
