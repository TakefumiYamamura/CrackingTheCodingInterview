#include <iostream>
#include <vector>
#include <map>

using namespace std;

pair<int, int> max_alive_year(vector<pair<int, int> > years){
	map<int, int> mp;
	for (int i = 0; i < years.size(); ++i)
	{
		mp[years[i].first] = 0;
		mp[years[i].second] = 0;
	}
	for (int i = 0; i < years.size(); ++i)
	{
		mp[years[i].first]++;
		auto next = mp.find(years[i].second);
		next++;
		if(next != mp.end()){
			next->second--;
		}
	}
	auto itr = mp.begin();
	auto pre = itr;
	itr++;
	while(itr != mp.end()){
		itr->second += pre->second;
		pre = itr;
		itr++;
	}
	int max_v = 0;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr)
	{
		max_v = max(max_v, itr->second);
	}

	pair<int, int> ans;
	bool find_flag = false;

	for (auto itr = mp.begin(); itr != mp.end(); ++itr)
	{
		if(max_v == itr->second){
			if(!find_flag) ans.first = itr->first;
			ans.second = itr->first;
			find_flag = true;			
		}
	}
	cout << ans.first << " : " << ans.second << endl;
	return ans;
}

int main(){
	vector<pair<int, int> > years;
	years.push_back(pair<int, int>(1990, 1992));
	years.push_back(pair<int, int>(1980, 1983));
	years.push_back(pair<int, int>(1980, 1995));
	years.push_back(pair<int, int>(1991, 2000));
	max_alive_year(years);
	years.push_back(pair<int, int>(1991, 1991));
	max_alive_year(years);
}
