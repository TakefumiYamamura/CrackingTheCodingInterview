#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <unordered_map>

using namespace std;


// time complexitiy is O(n**2)
unordered_set<string> us;
unordered_map<string, int> um;

int restore_sentence(string str){
	if(um.find(str) != um.end()){
		return um[str];
	}
	if(us.find(str) != us.end()){
		return um[str] = 0;
	}
	int ans = str.length();
	for (int i = 0; i < str.size() - 1; ++i)
	{
		count++;
		string str1 = str.substr(0, i+1);
		string str2 = str.substr(i+1);
		ans = min(ans, restore_sentence(str1) + restore_sentence(str2) );
	}
	return um[str] = ans;
}

int main(){
	string str = "jesslookedjustliketimherbrother";
	us.insert("looked");
	us.insert("just");
	us.insert("like");
	us.insert("her");
	us.insert("brother");
	cout << restore_sentence(str) << endl;
}

