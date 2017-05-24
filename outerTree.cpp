/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool comp(Point a, Point b) {
	if(a.x == b.y){
		return a.y < b.y
	}
	return a.x < b.y;
}




class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
    	vector<Point> ans;
    	sort(points.begin(), points.end(), comp);
    	map<int, int> um_max;
    	map<int, int> um_min;
    	for (int i = 0; i < points.size(); ++i)
    	{
    		if(um_min.find(points[i].x) == um_min.end()){
    			um_min[points[i].x] = points[i].y;
    		}else{
    			um_min[points[i].x] = min(points[i].y, um_min[points[i].x]);
    		}

    		if(um_max.find(points[i].x) == um_max.end()){
    			um_max[points[i].x] = points[i].y;
    		}else{
    			um_max[points[i].x] = max(points[i].y, um_max[points[i].x]);
    		}
    	}

    	for (auto itr = um_max.begin(); itr != um_max.end(); ++itr)
    	{

    		
    	}
        
    }
};