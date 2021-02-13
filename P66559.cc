#include <iostream>
using namespace std;

void escriu_triangle(int& t){
    bool entra, anterior;
    int c = 0, b = 0;
    for(int row = 1;row <= t*2;++row) {
        entra = false;
        anterior = false;
        for(int col = 1;col <= (t*2 + row); ++col) {
            //triangulo lado
            if(row <= ((t*2) - 1) and col <= ((t*2) - row))cout << " ";
            else if(not entra){ 
                if(b == 2) {
                    anterior = false;
                    b = 0;
                }
                //barras izquierda
                if( (col+row) % 2 != 0 and not anterior) {
                    cout << "/";
                    entra = true;
                }
                // espacios intermedios
                if(anterior and b < 2){
                    cout << " ";
                    ++b;
                }
                
            }
            else if(entra) {
                //barra baja
                if(row % 2 == 0  and c < 2){  
                    cout << "_";
                    ++c;
                }
                //barras derecha
                else if((col+row) % 2  == 0) {
                    cout << "\\";
                    entra = false;
                    c = 0;
                    if(row % 2 == 0)anterior = false;
                    else anterior = true;
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    int t;
    while(cin >> t and t > 0)escriu_triangle(t);
}
