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

class MaximumRangeDiv2	
{
public:
	 int findMax(string s){
		int max_v = 0;
		int min_v = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '+'){
				max_v++;
			}else{
				min_v++;
			}
		}
		return max(max_v, min_v);
	}
};
