class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	if(nums.size() == 0) return 0;
    	// vector<int> tmp;
    	// tmp.push_back(nums[0]);
    	// for (int i = 1; i < nums.size(); ++i)
    	// {
    	// 	if(tmp[tmp.size() - 1] <= nums[i]){
    	// 		tmp.push_back(nums[i]);
    	// 	}else{

    	// 	}
    	// }
    	vector<int> arr = nums;
    	map<int, int> mp;
		int max_v = INT_MIN;
		int left = -1;
		int right = -1;
		for (int i = 0; i < arr.size(); ++i)
		{
			if(max_v <= arr[i]){
				max_v = arr[i];
				if(mp.find(arr[i]) == mp.end()) mp[arr[i]] = i;
			}else{
				auto itr = mp.upper_bound(arr[i]);
				if(left == -1) left = itr->second;
				left = min(left, itr->second);
				right = i;
			}
		}
		if(left == -1 && right == -1){
			return 0;
		}else{
			return right - left + 1;
		}
	        
	}
};