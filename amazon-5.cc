/*
 * Complete the function below.
 */
#include <unordered_map>
vector < string > BitPattern(vector < int > num) {
	unordered_map<int, int> l_hash;
	unordered_map<int, int> r_hash;
	vector<string> ans;
	string tmp1 = "";
	string tmp2 = "";
	for (int i = 0; i < num.size(); ++i)
	{
		if(l_hash[num[i]] > 0){
			tmp1 += "1";
		}else{
			tmp1 += "0";
		}
		l_hash[num[i]] += 1;
	}
	for (int i = 0; i < num.size(); ++i)
	{
		l_hash[num[i]] -= 1;
		if(l_hash[num[i]] > 0){
			tmp2 += "1";
		}else{
			tmp2 += "0";
		}
	}
	ans.push_back(tmp1);
	ans.push_back(tmp2);
	return ans;
}

z
