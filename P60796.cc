#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct nod {
    int x;
    int y;
    int dis;
};

typedef vector< vector <char> > Matrix;

void bfs(Matrix& map, int x, int y) {
    queue<nod> por_visitar;
    nod a;
    a.x = x;
    a.y = y;
    a.dis = 0;
    por_visitar.push(a);
    map[x][y] = 'X';
    bool found = false;
    while(not por_visitar.empty()){
        a = por_visitar.front();
        por_visitar.pop();
        if(map[a.x+1][a.y] == 't' or map[a.x-1][a.y] == 't' or map[a.x][a.y+1] == 't' or map[a.x][a.y-1] == 't'){
            found = true;
        }
        if(map[a.x+1][a.y] == '.'){
            map[a.x+1][a.y] = 'X';
            nod b = a;
            ++b.x;
            ++b.dis;
            por_visitar.push(b);
        }
        if(map[a.x-1][a.y] == '.'){
            map[a.x-1][a.y] = 'X';
            nod b = a;
            --b.x;
            ++b.dis;
            por_visitar.push(b);
        }
        if(map[a.x][a.y+1] == '.'){
            map[a.x][a.y+1] = 'X';
            nod b = a;
            ++b.y;
            ++b.dis;
            por_visitar.push(b);
        }
        if(map[a.x][a.y-1] == '.'){
            map[a.x][a.y-1] = 'X';
            nod b = a;
            --b.y;
            ++b.dis;
            por_visitar.push(b);
        }
        if(found){
            cout << "minimum distance: "<< a.dis + 1 << endl;
            return;
        }

    }
    cout << "no treasure can be reached" << endl;
}

int main () {
    int n, m;
    cin >> n >> m;
    Matrix map(n+2,vector <char>(m+2));
    
    for(int i = 0;i < n + 2;++i){
        for(int j = 0;j < m + 2;++j) {
            if(i == 0 or j == 0 or i == n + 1 or j == m + 1)map[i][j] = 'X';
            else cin >> map[i][j];
        }
    }
//     for(int i = 0;i < n + 2;++i){
//         for(int j = 0;j < m + 2;++j) {
//             cout << map[i][j];
//         }
//         cout << endl;
//     }
    int x, y;
    cin >> x >> y;
    bfs(map,x,y);
}
