#include <iostream>
#include <vector>
#include <list>

using namespace std;



struct lst{
	list <int> adj;
	bool visited;
};

typedef vector < lst > matrix; 
bool DFS(matrix& m,int i, int ant){
	if(m[i].visited) return false;
	m[i].visited = true;
	list<int>:: iterator it = m[i].adj.begin();
	while(it !=  m[i].adj.end()){
		if((*it) != ant){
			if(not DFS(m,(*it),i))return false;
		}
		++it;
	}
	return true;
}

int main () {
	int v;
	while(cin >> v){
		int e, v1, v2, n_trees = 0;
		cin >> e;
		lst a;
		a.visited = false;
		matrix m (v,a);
		for(int i = 0;i < e;++i){
			cin >> v1 >> v2;
			m[v1].adj.push_back(v2);
			m[v2].adj.push_back(v1);
		}
		bool arb = true;
		for(int i=0;i < v and arb;++i){
			if(not m[i].visited){
				++n_trees;
				arb = DFS(m,i,-1);
			}
		}
		if(not arb)cout << "no" << endl;
		else cout << n_trees << endl;	
	}
}
