#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <unordered_map>

using namespace std;

bool can_match(int a_len, int b_len, string pattern, string str){
	int str_i = 0;
	unordered_map<char, string> um;
	string a = "";
	for (int i = 0; i < pattern.length(); ++i)
	{

		if(pattern[i] == 'a'){
			if(um.find(pattern[i]) == um.end()){
				um[pattern[i]] = str.substr(str_i, a_len);
				cout << um[pattern[i]] << endl;
			}else{
				cout << str.substr(str_i, a_len) << endl;
				if(um[pattern[i]] != str.substr(str_i, a_len)) return false;
			}
			str_i += a_len;
		}else{
			if(um.find(pattern[i]) == um.end()){
				um[pattern[i]] = str.substr(str_i, b_len);
				cout << um[pattern[i]] << endl;
			}else{
				cout << str.substr(str_i, b_len) << endl;
				if(um[pattern[i]] != str.substr(str_i, b_len)) return false;
			}
			str_i += b_len;
		}
	}
	return true;

}

bool match(string pattern, string str){
	int a_count = 0;
	int b_count = 0;
	int size = str.length();
	for (int i = 0; i < pattern.length(); ++i)
	{
		if(pattern[i] == 'a'){
			a_count++;
		} else {
			b_count++;
		}
	}
	for (int a_len = 0; a_len <= size; ++a_len)
	{
		if( (size - a_len * a_count) >= 0 && (size - a_len * a_count) % b_count == 0){ 
			cout << a_len << " " << (size - a_len * a_count) / b_count << endl;
			if(can_match(a_len, (size - a_len * a_count) / b_count , pattern, str )) return true;
		}
	}
	return false;
}

int main(){
	string pattern = "aabab";
	string str = "catcatgocatgo";
	cout << match(pattern, str) << endl;
}
