#include <string>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point
{
	double x, y;
	static bool Asc(const Point& a, const Point& b){
		if(a.x == b.x){
			return a.y < b.y;
		}else{
			return a.x < b.x;
		}
	}
};

class Sikaku
{
private:
	vector<Point> points;
public:
	Sikaku(){
		for (int i = 0; i < 4; ++i)
		{
			Point tmpP;
			cin >> tmpP.x >> tmpP.y;
			points.push_back(tmpP);
		}
		//ソートさせることで、正方形の位置関係を確定させる.
		//左下が0 右上が3になるので一番遠い要素の位置関係がわかる。
		sort(points.begin(), points.end(), Point::Asc);
		for (int i = 0; i < 4; ++i)
		{
			cout << points[i].x << points[i].y << endl;
		}
	}

	Point vec(Point a, Point b){
		Point tmpP = {b.x - a.x, b.y - a.y};
		return tmpP;
	}

	double length(Point a, Point b){
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	}

	bool isOrthogonal(Point a, Point b){
		if(a.x * b.x + a.y * b.y == 0){
			return true;
		}
		return false;
	}

	void exec(){
		Point ab = vec(points[0], points[1]);
		Point ac = vec(points[0], points[2]);
		Point db = vec(points[3], points[1]);
		Point dc = vec(points[3], points[2]);
		double abL = length(points[0], points[1]);
		double acL = length(points[0], points[2]);
		double dbL = length(points[3], points[1]);
		double dcL = length(points[3], points[2]);
		if(isOrthogonal(ab, ac) && isOrthogonal(db, dc)){
			if(abL == acL && acL == dbL && dbL == dcL){
				//全ての角度が90度で４辺の長さが全て等しい時は正方形
				cout << 1 << endl;
				return;
			}
			cout << 2 << endl;
		}else{
			cout << 0 << endl;
		}
	}	

};

int main(){
	Sikaku s = Sikaku();
	s.exec();
}
