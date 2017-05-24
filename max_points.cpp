/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd( int m, int n ) {
        if(m < 0) m *= -1;
        if(n < 0) n *= -1;
        if ( ( 0 == m ) || ( 0 == n ) )
            return 0;
        while( m != n )
        {
            if ( m > n ) m = m - n;
            else         n = n - m;
        }
        return m;
    }
    int maxPoints(vector<Point>& points) {
        unordered_map<int, unordered_map<int, int> > um;
        int ans = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            int duplicate = 1;
            um.clear();
            for (int j = i+1; j < points.size(); ++j)
            {
                int x1 = points[i].x;
                int y1 = points[i].y;
                int x2 = points[j].x;
                int y2 = points[j].y;
                if(x1 == x2){
                    if(y1 == y2){
                        duplicate++;
                    }else{
                        um[INT_MAX][0]++;
                    }
                    continue;
                }
                if(y1 == y2){
                    um[0][INT_MAX]++;
                    continue;
                }
                int a = (y1 - y2);
                int b = (x1 - x2);
                int m = gcd(a, b);
                if(a/m < 0){
                    a *= -1;
                    b *= -1;
                }
                um[a/m][b/m]++;
            }
            ans = max(ans, duplicate);

            for (auto itr = um.begin(); itr != um.end() ; ++itr)
            {

                unordered_map<int, int> um2 = itr->second;
                for (auto itr2 = um2.begin(); itr2 != um2.end() ; ++itr2)
                {
                    ans = max(ans, itr2->second + duplicate);
                }
            }
        }
        return ans;
        
    }
};
