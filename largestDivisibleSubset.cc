class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> dp = vector<int>(size, 1);
        for (int i = 0; i < size; ++i){
            for (int j = i-1; j >= 0; --j){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int max_index = 0;
        for (int i = 0; i < size; ++i){
            max_index = dp[i] > dp[max_index] ? i : max_index; 
        }

        vector<int> ans;
        int set_count = dp[max_index];
        for (int i = max_index; i >= 0 ; --i)
        {
            if(nums[max_index] % nums[i] == 0&& dp[i] == set_count){
                ans.push_back(nums[i]);
                set_count--;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
