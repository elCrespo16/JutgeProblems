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