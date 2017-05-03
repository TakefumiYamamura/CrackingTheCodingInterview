#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string find_longest_sub_array(string str){
	int size = str.size();
	vector<int> a = vector<int>(size, 0);
	vector<int> b = vector<int>(size, 0);
	vector<int> dif = vector<int>(size, 0);
	for (int i = 0; i < size; ++i)
	{
		if(str[i] == 'a'){
			a[i]++;
		}else{
			b[i]++;
		}
	}
	
	for (int i = 1; i < size; ++i)
	{
		a[i] += a[i-1];
		b[i] += b[i-1];
	}

	string ans = "";

	unordered_map<int, int> um;
	for (int i = 0; i < size; ++i)
	{
		dif[i] = a[i] - b[i];
		um[dif[i]] = i;
	}
	int ans_len = 0;
	if(um.find(0) != um.end()){
		ans = str.substr(0, um[0] + 1);
		ans_len = ans.length(); 
	}
	for (int i = 0; i < size; ++i)
	{
		if(um[dif[i]] == i) continue;
		int len = um[dif[i]] - i;
		if(len > ans_len){
			ans_len = len;
			ans = str.substr(i+1, um[dif[i]] - i);
		}
	}

	return ans;
}

int main(){
	cout << find_longest_sub_array("a1aaaa11a11aa1aa1aaaaa11111111") << endl;
	cout << find_longest_sub_array("a1aaaa11a11aa1aa1aaaaa") << endl;
}
