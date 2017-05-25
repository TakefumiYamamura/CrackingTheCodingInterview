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

	bool in_line(Point p){
		if(min(start.x, end.x) <= p.x && p.x < max(start.x, end.x)) {
			if(min(start.y, end.y) <= p.y && p.y < max(start.y, end.y)) {
				return true;
			}
		}
		return false;
	}
};

bool intersect(Line a, Line b){
	if(a.slope == b.slope){
		if(a.segment == b.segment){
			cout << "those line are same" << endl;
			return true;
		}else{
			return false;
		}
	}
	double tmp_x = (b.segment - a.segment) / (a.slope - b.slope);
	double tmp_y = a.slope * tmp_x + a.segment;
	Point ans_p = Point(tmp_x, tmp_y);
	if(a.in_line(ans_p) && b.in_line(ans_p)){
		cout << tmp_x << " " << tmp_y << endl;
		return true;
	}else{
		return false;
	}
}


int main(){
	Point a1 = Point(0, 0);
	Point a2 = Point(0, 1);
	Point a3 = Point(0, 2);
	Point a4 = Point(2.5, 2.5);
	Point a5 = Point(0, 5.0);
	Point a6 = Point(1, 0);
	Line l1 = Line(a1, a2);
	Line l2 = Line(a1, a3);
	Line l3 = Line(a1, a4);
	Line l4 = Line(a5, a6);
	intersect(l1, l2);
	intersect(l3, l4);
}