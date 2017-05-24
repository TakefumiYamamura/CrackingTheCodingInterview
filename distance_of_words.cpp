#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int distance_of_words(string str, string str1, string str2){
	string tmp = "";
	vector<string> words;
	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i] == '.' || str[i] == ',') continue;
		if(str[i] == ' '){
			while(str[i] == ' ' && i < str.size()) i++;
			words.push_back(tmp);
			tmp = "";
		}
		tmp += str[i];
	}
	if(tmp != "") words.push_back(tmp);

	unordered_map<string, vector<int> > um;

	for (int i = 0; i < words.size(); ++i)
	{
		um[words[i]].push_back(i);
	}

	vector<int> v1 = um[str1];
	vector<int> v2 = um[str2];
	int i1 = 0;
	int i2 = 0;
	int ans = INT_MAX/2;
	while(i1 != v1.size() && i2 != v2.size()){
		// cout << v1[i1] << " " << v2[i2] << endl;
		if(v1[i1] > v2[i2]){
			ans = min(v1[i1] - v2[i2] - 1, ans);
			i2++;
		}else{
			ans = min(v2[i2] - v1[i1] - 1, ans);
			i1++;
		}
	}
	return ans;
}


int main(){
	string str = "I have a dream that one day down in Alabama, with its vicious racists, with its governor having his lips dripping with the words of interposition and nullification one day right there in Alabama little black boys and black girls will be able to join hands with little white boys and white girls as sisters and brothers. I have a dream today.";
	cout << distance_of_words(str, "dream", "day") << endl;

}