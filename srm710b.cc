#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class ForwardMancala
{
public:
	bool checkAns(vector<int> ans){
		int count = 0;
		for (int i = 0; i < ans.size(); ++i)
		{
			if(ans[i] > 0) count++;
			if(count > 1) return false; 
		}
		if(count == 1) return true;
		return false;
	}

	vector <int> findMoves(vector <int> start){
		vector<int> state = start;
		vector<int> ans;
		int n = start.size();
		for (int i = 0; i <= 2500; ++i)
		{
			if(checkAns(state))return ans;
			int min_v = 10 * 20;
			int min_idx = 0;
			for (int j = 0; j < n; ++j)
			{
				if(state[j] < min_v && state[j] != 0){
					min_v = state[j];
					min_idx = j;
				}
			}
			state[min_idx] = 0;
			ans.push_back(min_idx);
			for (int j = min_v; j > 0; --j)
			{
				min_idx++;
				min_idx %= n;
				state[min_idx]++;
			}
		}
		return ans;
	}
};
