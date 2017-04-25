class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp = vector<int>(n+2, INT_MAX);
        //dp[i][j] i番目までの数をつかってj個の部分列を作れる時の最小値
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            vector<int> new_dp = dp;
            for (int j = 0; j <= i+1; ++j)
            {
                dp[j] = min(new_dp[j], dp[j]);
                if(new_dp[j-1] < nums[i]) dp[j] = min(dp[j], nums[i]);
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; ++i)
        {
            if(dp[i] != INT_MAX) ans = i;
        }
        return ans;
        
    }
};
