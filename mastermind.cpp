#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <climits>
#include <unordered_map>
#include <string>
#include <assert.h>
using namespace std;

void master_mind(string ans, string input){
	assert(ans.length() == input.length());
	unordered_set<char> ust;
	int hit = 0;
	int brow = 0;
	for (int i = 0; i < ans.size(); ++i)
	{
		if(ans[i] == input[i]) hit++;
		ust.insert(input[i]);
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		if(ans[i] != input[i] && ust.find(ans[i]) != ust.end()) brow++;
	}

	cout << hit << " : " << brow << endl;


}

int main(){
	vector<int> arr;
	for (int i = 1; i <= 100; ++i)
	{
		if(i == 29 || i == 47) continue;
		arr.push_back(i);
	}
	master_mind("RGBY", "GGRR");
}
