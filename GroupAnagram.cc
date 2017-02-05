#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

class HashCompare {// ハッシュ関数オブジェクト
public:
    int operator()(const vector<int> &x) const {
        const int C = 997;// 素数
        int t = 0;
        for (int i = 0; i != x.size(); ++i) {
            t = t * C + x[i];
        }
        return t;
    }
};


void groupAnagrams(vector<string> array){
	vector<string> ans;
	unordered_map<vector<int>, vector<string>, HashCompare> hash;
	for (int i = 0; i < array.size(); ++i)
	{
		string tmp = array[i];
		vector<int> key = vector<int>(256, 0);
		for (int j = 0; j < tmp.length(); ++j)
		{
			key[tmp[j] - 'a']++;
		}
		hash[key].push_back(tmp);
	}
	for (auto itr = hash.begin() ; itr != hash.end(); ++itr)
	{
		vector<string> tmp = itr->second;
		for (int j = 0; j < tmp.size(); ++j)
		{
			ans.push_back(tmp[j]);
		}
	}
	array = ans;
}

int main(){
	vector<string> test;
	test.push_back("abcd");
	test.push_back("ad");
	test.push_back("xyz");
	test.push_back("dabc");
	test.push_back("adbc");
	test.push_back("yzx");
	test.push_back("yyyyyyy");
	groupAnagrams(test); 
	for (int i = 0; i < test.size(); ++i)
	{
		cout << test[i] << endl;
	}
}