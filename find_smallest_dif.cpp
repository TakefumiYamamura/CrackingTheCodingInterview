#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;


int find_smallest_dif(vector<int> a, vector<int> b){
	set<int> st_a;
	for (int i = 0; i < a.size(); ++i)
	{
		st_a.insert(a[i]); 
	}
	int ans = INT_MAX/2;

	for (int i = 0; i < b.size(); ++i)
	{
		auto itr = st_a.lower_bound(b[i]);
		if(itr != st_a.end()) ans = min(ans, *itr - b[i]);
		if(itr !=st_a.begin()){
			itr--;
			ans = min(ans, b[i] - *itr);
		}
	}
	return ans;
}

int main(){
	vector<int> a{1, 3, 15, 11, 2};
	vector<int> b{-100, 23, 127, 235, 19, 8, 500};
	cout << find_smallest_dif(a, b) << endl;
}
