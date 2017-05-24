#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> permutaions(string str){
	vector<string> ans;
	ans.push_back("");
	for (int i = 0; i < str.length(); ++i)
	{
		vector<string> new_ans;
		unordered_map<string, bool> hash; 
		for (int j = 0; j < ans.size(); ++j)
		{
			for (int k = 0; k <= ans[j].size(); ++k)
			{
				string new_str = ans[j];
				new_str.insert(new_str.begin() + k, str[i]);
				if(hash.find(new_str) == hash.end()) new_ans.push_back(new_str);
				hash[new_str] = true;
			}
		}
		ans = new_ans;
	}
	return ans;
}

int main(){
	vector<string> ans = permutaions("11122");
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
}
