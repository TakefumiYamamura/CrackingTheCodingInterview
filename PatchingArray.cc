class Solution
{
public:
	int minPatches(vector<int>& nums, int n){
		map<int, int> hash;
		for (int i = 0; i < 1<<nums.size(); ++i)
		{
			int sum = 0;
			int tmp = i;
			int index = 0;
			while(tmp > 0){
				if(tmp & 1) sum += nums[index];
				tmp = tmp >> 1;
				index++;
			}
			hash[sum] = 1;
			// cout << sum <<" ";
		}
		// cout << endl;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			map<int, int> tmp_hash = hash;
			if(hash.find(i) == hash.end()){
				ans++;
				int tmp = i;
				tmp_hash[i] = 1;
				for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
					if(tmp + itr->first > n) break;
					tmp_hash[tmp + itr->first] = 1;
					// cout << tmp + itr->first <<" ";
				}
				// cout << endl;
			}
			hash = tmp_hash;
		}
		return ans;
	}
};
