#include <iostream>

using namespace std;

struct Rectangle {
	int x_left, x_right, y_down, y_up;
};

void read(Rectangle& r){
	cin >> r.x_left >> r.x_right >> r.y_down >> r.y_up;
}
int relationship(const Rectangle& r1, const Rectangle& r2) {
	if (r1.x_left == r2.x_left and r1.x_right == r2.x_right and r1.y_down == r2.y_down && r1.y_up == r2.y_up) return 4;
    if (r2.x_left <= r1.x_left and r2.x_right >= r1.x_right and r2.y_down <= r1.y_down && r2.y_up >= r1.y_up) return 1;
    if (r1.x_left <= r2.x_left and r1.x_right >= r2.x_right and r1.y_down <= r2.y_down && r1.y_up >= r2.y_up) return 2;
    if (r1.y_down > r2.y_up or r2.y_down > r1. y_up or r1.x_left > r2.x_right or r2.x_left > r1.x_right) return 0;
    else return 3;
}
int main() {
	int n;
	cin >> n;
	Rectangle r1, r2;
	for (int i = 0; i < n; ++i){
		read(r1);
		read(r2);
		int sol = relationship(r1, r2);
		if (sol == 1) cout << "the first rectangle is inside the second one";
		else if (sol == 2) cout << "the second rectangle is inside the first one";
		else if (sol == 3) cout << "rectangles intersect";
		else if (sol == 4) cout << "rectangles are identical";
		else cout << "rectangles do not intersect";
		cout << endl;
	}
}