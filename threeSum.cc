class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int> > ans;
    	sort(nums.begin(), nums.end());
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if(i > 0 && nums[i] == nums[i-1]) continue;
    		for (int j = i+1, k = nums.size() - 1; j < k;)
    		{
    			if(j > i+1 && nums[j] == nums[j-1]){
    				j++;
    				continue;
    			}
    			if(nums[i] + nums[j] + nums[k] == 0){
    				ans.push_back({nums[i], nums[j], nums[k]});
    				j++;
    			}else if(nums[i] + nums[j] + nums[k] > 0){
    				k--;
    			}else{
    				j++;
    			}
    		}
    	}
    	return ans;
    }
};