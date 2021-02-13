#include <iostream>
using namespace std;

//saca el numero de segundos
int main () {
    int year, day, hour, min, sec;
    cin >> year >> day >> hour >> min >> sec;
    day = day + (year * 365);
    hour = hour + (day * 24);
    min = min + (hour * 60);
    sec = sec + (min * 60);
    cout << sec << endl;
}