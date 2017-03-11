#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class MagicSubset
{
public:
	int findBest(vector<int> values){
		int nega_ans = values[0];
		int posi_ans = 0;
		for (int i = 1; i < values.size(); ++i)
		{
			if(values[i] > 0){
				posi_ans += values[i];
			}else{
				nega_ans += values[i];
			}
		}
		return max(0, max(-1 * nega_ans, posi_ans));
	}
};
