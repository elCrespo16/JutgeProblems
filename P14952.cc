#include <iostream>
#include <vector>
#include <queue>
#include <list>
 
#define DEBUG 0
 
using namespace std;
 
 
void ordenacio_topologica(vector< vector<int> > &tasques, vector<int> &apuntados) {
    int n = tasques.size();
    priority_queue<int, vector<int>, greater<int> > cola_prioridad;
 
    for (int i = 0; i < n; i++)
        if (apuntados[i] == 0) cola_prioridad.push(i);
 
    list<int> lista;
    while (not cola_prioridad.empty()) {
        int u = cola_prioridad.top();
        lista.push_back(u);
        cola_prioridad.pop();
        int m = tasques[u].size();
        for (int i = 0; i < m; i++) {
            int v = tasques[u][i];
            if (--apuntados[v] == 0) cola_prioridad.push(v);
        }
    }
 
    if (not lista.empty()) {
		cout << lista.front(); 
		lista.pop_front();
	}
    while (not lista.empty()) {
        cout << ' ' << lista.front();
        lista.pop_front();
    }
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        vector< vector<int> > tasques(n);
        vector<int> apuntados(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            tasques[u].push_back(v);
            apuntados[v]++;
        }
        ordenacio_topologica(tasques, apuntados);
        cout << endl;
    }
}