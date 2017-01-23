#include <iostream>
#include <string>
using namespace std;

string compression(string str){
	string ans = "";
	for (int i = 0; i < str.length(); ++i)
	{
		int j = i;
		int count = 0;
		while(str[i] == str[j]){
			count++;
			j++;
		}
		ans += str[i];
		ans += to_string(count);
		i = j-1;
	}
	return ans;
}


int main(){
	cout << compression("aabcccccaaa") << endl;

}
