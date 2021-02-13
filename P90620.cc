#include <iostream>
using namespace std;

int main () {
    int pre, mid, post;
    bool a = false;
    cin >> pre >> mid >> post;
    if(mid > pre and mid > post and mid > 3143) {
	cout << "SI" << endl;
	return 0;
    }
    while(not a) {
	pre = mid;
	mid = post;
	cin >> post;
	if(post == 0)a = true;
	else if(mid > pre and mid > post and mid > 3143) {
	    cout << "SI" << endl;
	    return 0;
	}
    }
    cout << "NO" << endl;

}