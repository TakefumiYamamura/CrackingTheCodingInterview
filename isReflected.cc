
class Solution {
	map<pair<int, int>, bool> hash;
public:
    bool isReflected(vector<pair<int, int>>& points) {
    	sort(points.begin(), points.end());
    	if(points.size() == 0) return true;
    	pair<int, int> front = points[0];
    	pair<int, int> end = points[points.size() - 1];
    	double mid = (front.first + end.first) / 2.0;
    	for (int i = 0; i < points.size(); ++i)
    	 {
    	 	hash[points[i]] = true; 
    	 }
    	for (int i = 0; i < points.size(); ++i)
    	{
    		pair<int, int> tmp = points[i];
    		tmp.first = -1 * tmp.first + mid * 2.0;
    		if(hash.find(tmp) == hash.end()) return false;
    	}
    	return true;
    }
};