#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> permutaions(string str){
	vector<string> ans;
	ans.push_back("");
	for (int i = 0; i < str.length(); ++i)
	{
		vector<string> new_ans;
		for (int j = 0; j < ans.size(); ++j)
		{
			for (int k = 0; k < ans[j].size(); ++k)
			{
				string new_str = ans[j];
				new_str.insert(new_str.begin() + k, str[i]);
				new_ans.push_back(new_str);
			}
			string add_str = ans[j];
			add_str += str[i];
			new_ans.push_back(add_str);
		}
		ans = new_ans;
	}
	return ans;
}

int main(){
	vector<string> ans = permutaions("012345");
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
}
