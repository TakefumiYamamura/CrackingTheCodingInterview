#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define MOD 1000000007
// INT_MAX
using namespace std;

class ImageCompression
{
public:
	 string isPossible(vector <string> image, int k){
		int x = image.size();
		int y = image[0].length();
		if( x % k != 0 || y % k != 0) return "Impossible";
		vector<vector<int> > visited = vector<vector<int> >(x, vector<int>(y, 0));
		for (int i = 0; i < x; )
		{
			for (int j = 0; j < y; )
			{
				for (int t1 = 0; t1 < k; ++t1)
				{
					for (int t2 = 0; t2 < k; ++t2)
					{
						if(image[i][j] != image[i+t1][j+t2]) return "Impossible";
					}
				}
				j += k;
			}
			i += k;
		}
		return "Possible";

	}
};
