#include <iostream>
#include <cmath>
using namespace std;
 
struct Punt {
        double x, y;
};
 
struct Cercle {
        Punt centre;
        double radi;
};
 
double distancia(const Punt&a, const Punt&b) {
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
 
void desplaca(Punt&p1, const Punt&p2) {
        p1.x += p2.x;
        p1.y += p2.y;
}
 
void escala(Cercle&c, double esc) {
        c.radi *= esc;
}
 
void desplaca(Cercle&c, const Punt&p) {
        desplaca(c.centre, p);
}
 
bool es_interior(const Punt&p, const Cercle&c) {
        return (distancia(p, c.centre) < c.radi);
}
 
void llegeix(Punt&p) {
        cin >> p.x >> p.y;
}
 
void llegeix(Cercle&c) {
        cin >> c.centre.x >> c.centre.y >> c.radi;
}
 
int main() {
        Cercle c;
        llegeix(c);
        Punt p;
        llegeix(p);
        bool esinterior = es_interior(p, c);
        if (esinterior) cout << "inicialment a dins" << endl;
        else cout << "inicialment a fora" << endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
                Punt q;
                llegeix(q);
                desplaca(p, q);
                if (esinterior and not es_interior(p, c)) {
                        esinterior = false;
                        cout << "al pas " << i << " ha sortit a fora" << endl;
                }
                else if (not esinterior and es_interior(p, c)) {
                        esinterior = true;
                        cout << "al pas " << i << " ha entrat a dins" << endl;
                }
        }
}