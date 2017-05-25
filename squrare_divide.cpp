#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <float.h>
using namespace std;

const double INF = DBL_MAX / 2;

class Point
{
public:
	double x;
	double y;
	Point(){}
	Point(double x_, double y_) : x(x_), y(y_) {}
	Point operator + (const Point&  p){
		return Point(x + p.x, y + p.y); 
	}
	Point operator - (const Point&  p){
		return Point(x - p.x, y - p.y); 
	}
};

struct Line
{
	Point start;
	Point end;
	double slope;
	double segment;
	Line(Point start_, Point end_) : start(start_), end(end_) {
		Point tmp_p = start - end;
		slope = tmp_p.x == 0 ? INF : tmp_p.y / tmp_p.x;
		segment = start.y - slope * start.x;
	}
};

struct Square
{
	double len;
	Point center;
	Square(double len_, Point center_) : len(len_), center(center_) {}
};

Line find_divide(Square s1, Square s2){
	return Line(s1.center, s2.center);
}

int main(){
	Square s1 = Square(9.3, Point(0, 3.75));
	Square s2 = Square(3.56, Point(1.05, 3.375));
	Line l = find_divide(s1, s2);
	cout << l.slope << " " << l.segment << endl;
}
