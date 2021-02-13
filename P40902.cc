#include <map>
#include <string>
#include <iostream>

using namespace std;

void error (const string& name){
    cout << name <<" is not in the casino" << endl;
}

int main () {
    string name, comand;
    map <string,int> casino;
    map <string,int>::iterator it = casino.begin();
    while(cin >> name) {
        it = casino.find(name);
        cin >> comand;
        if (comand == "enters") {
            if (it != casino.end()) cout << name <<" is already in the casino" << endl;
            else casino.insert(make_pair(name,0));
        }
        else if (comand == "wins") {
            int num;
            cin >> num;
            if(it == casino.end()) error(name);
            else (*it).second += num;
        }
        else {
            if(it == casino.end()) error(name);
            else {
                cout << (*it).first << " has won " << (*it).second << endl;
                casino.erase(it);
            }
        }
    }
    cout << "----------" << endl;
    
    for (it = casino.begin();it != casino.end();++it){
        cout << (*it).first << " is winning " << (*it).second << endl;
    }
}
