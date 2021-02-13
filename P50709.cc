#include <iostream>
#include <queue>

using namespace std;

void error() {
    cout << "error!" << endl;
}

int main () {
    char inp;
    priority_queue <int> xd;
    while(cin >> inp) {
        if (inp == 'S'){
            int num;
            cin >> num;
            xd.push(num);
        }
        else if(inp == 'A'){
            if (xd.empty()) error();
            else cout << xd.top() << endl;
        }
        else if(inp == 'R'){
            if (xd.empty()) error();
            else xd.pop();
        }
        else if(inp == 'I'){
            int sum;
            cin >> sum;
             if (xd.empty()) error();
            else {
                int a = xd.top();
                xd.pop();
                a += sum;
                xd.push(a);
            }
        }
        else {
            int sum;
            cin >> sum;
             if (xd.empty()) error();
            else {
                int a = xd.top();
                xd.pop();
                a -= sum;
                xd.push(a);
            }
        }
        
    }
}
