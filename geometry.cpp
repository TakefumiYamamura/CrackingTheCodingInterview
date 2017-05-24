#include <iostream>
#include <algorithm>


#define EPS (1e - 10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

using namespace std;

class Point {
private:
	double x;
	double y;
public:
	Point(double _x = 0, double _y = 0): x(_x), y(_y){}

	Point operator + (Point p) {return Point(x + p.x, y + p.y); }
	Point operator - (Point p) {return Point(x - p.x, y - p.y); }
	Point operator * (double k) {return Point(x * k, y * k); }
	Point operator / (double k) {return Point(x / k, y / k); }

	double abs(){
		return sqrt(norm());
	}

	double norm(){
		return x * x + y * y;
	}

	bool operator < (const Point &p) const {
		return x != p.x ?  x < p.x : y < p.y;
	}

	bool operator == (const Point &p) const {
		return fabs(x - p.x) < EPS  && fabs(y - p.y) < EPS;
	}

};

typedef Point Vector;

struct Segment{
	Point p1;
	Point p2;
};

typedef Segment Line;

class Circle {
public:
	point c;
	double r;
	Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

typedef vector<Point> Polygon;

