#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define INF INT_MAX/2

using namespace std;


void shortest_super_sequence(vector<int> short_arr, vector<int> long_arr){
	vector<int> dp = vector<int>(short_arr.size(), -1);
	int min_len =  INF;
	pair<int, int> min_pair;
	for (int i = 0; i < long_arr.size(); ++i)
	{
		for (int j = 0; j < short_arr.size(); ++j)
		{
			if(long_arr[i] == short_arr[j]){
				dp[j] = i;
			}
		}
		int min_v = INF;
		bool end_flag = false;
		for (int j = 0; j < short_arr.size(); ++j)
		{
			if(dp[j] == -1){
				end_flag = true;
				break;
			}
			min_v = min(min_v, dp[j]);
		}
		if(end_flag) continue;
		if(min_len > i - min_v){
			min_len = i - min_v;
			min_pair = pair<int, int>(min_v, i);
		}
	}
	if(min_len == INF){
		cout << "not found" << endl;
	}else{
		cout << min_pair.first << " " << min_pair.second << endl;
	}

}



int main(){
	vector<int> short_arr{1, 5, 9};
	vector<int> long_arr{7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7};
	shortest_super_sequence(short_arr, long_arr);
	vector<int> short_arr2{100, 5, 9};
	shortest_super_sequence(short_arr2, long_arr);


}
