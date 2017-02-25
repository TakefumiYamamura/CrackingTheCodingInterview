class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int> > ans;
    	for (int i = 0; i < (2 << (nums.size()-1) ) ; ++i)
    	{
    		int tmp = i;
    		vector<int> tmp_ans;
    		int digit = 0;
    		while(tmp > 0){
    			if(tmp & 1) tmp_ans.push_back(nums[digit]);
    			digit++;
    			tmp = tmp >> 1;
    		}
    		ans.push_back(tmp_ans);
    	}
    	return ans;
    }
};