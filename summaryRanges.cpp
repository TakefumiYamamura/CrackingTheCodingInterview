class Solution {
public:
	string create_string(int start, int end){
		return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
	}
    
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> ans;
    	if(nums.size() == 0) return ans;
    	int start = nums[0];
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		if(nums[i] - nums[i-1] != 1){
    			ans.push_back(create_string(start, nums[i-1]));
    			start = nums[i];
    		}
    	}
    	ans.push_back(create_string(start, nums[nums.size() - 1]) );
      	return ans;
    }
};