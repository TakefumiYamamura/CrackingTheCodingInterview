class Solution {
public:
    string optimalDivision(vector<int>& nums) {
    	// for (int i = 0; i < nums.size(); ++i)
    	// {
    	// 	new_nums.push_back(nums[i] * 1.0);
    	// }
    	string ans = "";
    	ans += to_string(nums[0]);
    	if(nums.size() != 1 && nums.size() != 2 ) ans += "/(";
    	if(nums.size() == 2) ans += "/";
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		ans += to_string(nums[i]);
    		if(i != nums.size() - 1 ) ans += "/";
    	}
    	if(nums.size() != 1 && nums.size() != 2 ) ans += ")";
    	return ans;
    }
};