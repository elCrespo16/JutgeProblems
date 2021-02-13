#include <iostream>
#include <cmath>

using namespace std;

struct Point {
         double x, y;
};

double dist(const Point& a, const Point& b){
	double cx = a.x - b.x;
	double cy = a.y - b.y;
	return sqrt ((cx*cx + cy*cy));
}

void move(Point& p1, const Point& p2){
	p1.x = p1.x + p2.x;
	p1.y = p1.y + p2.y;
}

struct Circle {
         Point center;
         double radius;
};

void scale(Circle& c, double sca){
	c.radius = c.radius * sca;
}

void move(Circle& c, const Point& p) {
	c.center.x = c.center.x + p.x;
	c.center.y = c.center.y + p.y;
}

bool is_inside(const Point& p, const Circle& c) {
	if (dist (p,c.center) > c.radius) return false;
	return true;
}

int main () {
}