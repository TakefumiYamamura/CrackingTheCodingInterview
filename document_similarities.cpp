#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <unordered_map>
#include <map>
using namespace std;

void calculate_similarities(vector<vector<int> > documents){
	unordered_map<int, vector<int> > uum;
	for (int i = 0; i < documents.size(); ++i)
	{
		for (int j = 0; j < documents[i].size(); ++j)
		{
			uum[documents[i][j]].push_back(i);
		}
	}

	map<pair<int, int>, int> pair_duplicates;
	for (auto itr = uum.begin(); itr != uum.end(); ++itr)
	{
		vector<int> arr = itr->second;
		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = i + 1; j < arr.size(); ++j)
			{
				pair_duplicates[pair<int, int>(arr[i] , arr[j])]++;
			}
		}
	}

	for (auto itr = pair_duplicates.begin(); itr != pair_duplicates.end(); ++itr)
	{
		int i1 = itr->first.first;
		int i2 = itr->first.second;
		cout << i1 << " : " << i2 << " " << 1.0 * itr->second /(documents[i1].size() + documents[i2].size() - itr->second) << endl; 
	}


}


int main(){
	vector<vector<int> > documents{{14, 15, 100, 9, 3},
									{32, 1, 9, 3, 5},
									{15, 29, 2, 6, 8, 7},
									{7, 10}								
									};
	calculate_similarities(documents);
}
