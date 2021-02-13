#include <iostream>
#include <vector>

using namespace std;

struct Persona {
    string nom;
    bool dona;
    int edat;
};

typedef vector <Persona> fila;

int fill_oldmen (fila& v,const int v_size){
    int old;
    old = -1;
    for(int i = 0;i < v_size;++i){
	string k;
	cin >> v[i].nom >> k;
	if(k == "dona") v[i].dona = true;
	else  v[i].dona = false;
	cin >> v[i].edat;
	if(not v[i].dona and v[i].edat > old)old = v[i].edat;
    }
    return old;
}

void suelta_dona (const fila& v,const int& v_size,const int& old) {
    for(int i = 0;i < v_size;++i) {
	if(v[i].dona and v[i].edat < old)cout << v[i].nom << " " << v[i].edat << endl;
    }
}

int main () {
    int k,old;
    cin >> k;
    fila v (k);
    old = fill_oldmen(v,k);
    suelta_dona(v,k,old);
}