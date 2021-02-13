#include <map>
#include <iostream>

using namespace std;

int main () {
    int x, y, n;
    while (cin >> x){
        map<int, int> exist;
        map<int, int>::iterator it;
        bool fuera = false;
        int counter = 1;
        cin >> y >> n;
        exist.insert(make_pair(n,0));
        while (n <= 100000000 and not fuera) {
            if (n % 2 == 0) {
                n = (n / 2) + x;
            }
            else {
                n = (3 * n) + y;
            }
            it = exist.find(n);
            if (it == exist.end()){
                    exist.insert(make_pair(n,counter));
            }
            else {
                    fuera = true;
                    cout << counter - (*it).second << endl;
            }
            ++counter;
        }
        if (not fuera) cout << n << endl;
    }
}
