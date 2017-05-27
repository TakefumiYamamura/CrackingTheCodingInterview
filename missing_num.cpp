#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


int i_bit_is_one(int n, int i){
	return (n >> (i - 1) ) & 1 ? 1 : 0;
}

int missing_number(vector<int> arr){
	int n = arr.size() + 1;
	int ans = 0;
	int pow_i = 1;
	int pow_tmp = 1;
	vector<int> tmp_arr = arr;
	string ans_s = "";
	while(n > 0){
		unordered_map<int, vector<int> > um;
		for (int i = 0; i < tmp_arr.size(); ++i)
		{
			um[i_bit_is_one(tmp_arr[i], pow_i)].push_back(tmp_arr[i]);
		}
		int cor_size = tmp_arr.size() + 1;
		int count_zero = cor_size / 2 + cor_size % 2;
		int count_one = cor_size / 2;
		// cout << count_zero << " " << count_one << endl;
		if(um[0].size()  == count_zero){
			tmp_arr = um[1];
			ans += pow_tmp * 1;
			ans_s = "1" + ans_s;
		}else{
			tmp_arr = um[0];
			ans_s = "0" + ans_s;
		}
		n = n >> 1;
		pow_tmp = pow_tmp * 2;
		pow_i++;
	}
	cout << ans_s << endl;
	return ans;

}

int main(){
	vector<int> arr;
	for (int i = 0; i < 117; ++i)
	{
		if(i == 59) continue;
		arr.push_back(i);
	}

	cout << missing_number(arr) << endl;

}
