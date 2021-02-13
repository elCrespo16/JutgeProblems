#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct word_times {
    string name;
    int rep;
};

bool les (const word_times& a, const word_times& b) {
    return a.name < b.name;
}

bool more (const word_times& a, const word_times& b) {
    if (a.rep == b.rep) return a.name < b.name;
    return a.rep > b.rep;
}

void fill (vector <word_times>& v,const int& n) {
    for (int i = 0;i < n;++i) {
	cin >> v[i].name;
    }
}

void count (vector <word_times>& v,const int& n) {
    string actual;
    int actual_pos = 0;
    actual = v[0].name;
    for (int i = 0;i < n;++i){
	if (v[i].name == actual)++v[actual_pos].rep;
	else {
	    ++v[i].rep;
	    actual_pos = i;
	    actual = v[i].name;
	}
    }
}

void suelta (const vector <word_times>& v, const int& k) {
    for (int i = 0;i < k;++i){
	cout << v[i].name << endl;
    }
    cout << "----------" << endl;
}

void print (const vector <word_times>& v,const int& n) {
    for(int i = 0;i < n;++i){
	cout << v[i].name << v[i].rep << " ";
    }
    cout << endl;
}

int main () {
    int n, k;
    while (cin >> n >> k and n != 0) {
	vector <word_times> v (n);
	fill(v,n);
	sort(v.begin(),v.end(),les);
	count(v,n);
	sort(v.begin(),v.end(),more);
	suelta(v,k);
    }
}