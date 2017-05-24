#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
private:
	unordered_map<string, int> hash;
public:
	Solution(){}

	int boolean_evaluation(string str, bool target){
		cout << str << endl;
		if(hash.find(str) != hash.end()) return hash[str];
		if(str.size() == 1){
			// if(str[0] != '1' && str[0] != '0') cout << str[0] << endl;
			if(target == str[0] - '0') return 1;
			return 0;
		}
		int count = 0;
		for (int i = 1; i+1 < str.size(); ++i)
		{
			if(str[i] == '0' || str[i] == '1') continue;
			bool new_i;
			if(str[i] == '&'){
				new_i = (str[i-1] - '0') & (str[i+1] - '0');
			}else if(str[i] == '^'){
				new_i = (str[i-1] - '0') ^ (str[i+1] - '0');
			}else if(str[i] == '|'){
				new_i = (str[i-1] - '0') | (str[i+1] - '0');
			}
			string new_str = str;
			new_str.erase(i - 1, 3);
			new_str.insert(i - 1, to_string(new_i) );
			count += boolean_evaluation(new_str, target);
		}
		hash[str] = count;
		return count;
	}
	
};

int main(){
	Solution s = Solution();
	cout << s.boolean_evaluation("1^0|0|1", false) << endl;
	cout << s.boolean_evaluation("0&0&0&1^1|0", true) << endl;
}
