#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> smalls = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
						 "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Nineteen"};
const vector<string> tens = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const string hundred = "Hundred";
const vector<string> bigs = {"", "Thousand", "Million", "Billion"};

string contert_low_three(string num){
	string ans = "";
	if(num == "000") return ans;
	string tmp = num.length() < 2 || num[1] == '0' ? num.substr(0, 1) : num.substr(0, 2);
	reverse(tmp.begin(), tmp.end());
	if(stoi(tmp) < 20){
		ans += smalls[stoi(tmp)];
	}else{
		ans += tens[stoi(tmp) / 10];
		if(stoi(tmp) % 10 != 0){
			ans  = ans + " " + smalls[stoi(tmp) % 10]; 
		}
	}
	if(num.length() == 3 && num[2] != '0'){
		string tmp1 = num.substr(2, 1);
		ans = smalls[stoi(tmp1)] + " Hundred " + ans; 
	}
	return ans;
}

string convertChunk(int number){
	cout << number << endl;
	string nums = to_string(number);
	reverse(nums.begin(), nums.end());
	string ans = "";
	int len = 0;
	while(len < nums.length()){
		string tmp = "";
		if(nums.length() - len >= 3){
			tmp = nums.substr(len, 3);
		}else if(nums.length() - len <= 2){
			tmp = nums.substr(len, 2);
		}else{
			tmp = nums.substr(len, 1);
		}

		ans = contert_low_three(tmp) + " " + bigs[len / 3] + " " +  ans;
		len += 3;
	}
	return ans;

}

int main(){
	// cout << contert_low_three("213") << endl;
	// cout << contert_low_three("020") << endl;
	// cout << contert_low_three("1") << endl;
	// cout << contert_low_three("105") << endl;
	cout << convertChunk(123456) << endl;
	cout << convertChunk(102000) << endl;
	cout << convertChunk(123456) << endl;
	cout << convertChunk(106438410) << endl;
	cout << convertChunk(123434156) << endl;
	cout << convertChunk(1020020) << endl;
}
